var requests = new Array();

if(typeof(XMLHttpRequest) == 'undefined')
var XMLHttpRequest = function()
{
	var request = null;
	try
	{
		request = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch(e)
	{
		try
		{
			request = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch(ee)
		{}
	}
	return request;
}

function ajax_stop()
{
	for(var i=0; i<requests.length; i++)
	{
		if(requests[i] != null)
			requests[i].abort();
	}
}

function ajax_create_request(context)
{
	for(var i=0; i<requests.length; i++)
	{
		if(requests[i].readyState == 4)
		{
			requests[i].abort();
			requests[i].context = context;
			return requests[i];
		}
	}

	var pos = requests.length;
	
	requests[pos] = Object();
	requests[pos].obj = new XMLHttpRequest();
	requests[pos].context = context;
	
	return requests[pos];
}

function ajax_request(url, data, callback, context)
{
	var request = ajax_create_request(context);
	var async = typeof(callback) == 'function';

	if(async) request.obj.onreadystatechange = function()
	{
		if(request.obj.readyState == 4)
			callback(new ajax_response(request));
	}
	
	request.obj.open('POST', url, async);
	request.obj.send(data);
	
	if(!async)
		return new ajax_response(request);
}

function ajax_response(request)
{
	this.request = request.obj;
	this.error = null;
	this.value = null;
	this.context = request.context;
	
	if(request.obj.status == 200)
	{
		try
		{
			this.value = object_from_json(request);
			
			if(this.value && this.value.error)
			{
				this.error = this.value.error;
				this.value = null;
			}
		}
		catch(e)
		{
			this.error = new ajax_error(e.name, e.description, e.number);
		}
	}
	else
	{
		this.error = new ajax_error('HTTP request failed with status: ' + request.obj.status, request.obj.status);
	}
	
	return this;
}

function enc(s)
{
	return s == null ? null : s.toString().replace(/\%/g, "%26").replace(/=/g, "%3D");
}

function object_from_json(request)
{
	if(request.obj.responseXML != null && request.obj.responseXML.xml != null && request.obj.responseXML.xml != '')
		return request.obj.responseXML;
	
	var r = null;	
	eval('r=' + request.obj.responseText + ';');	
	
	//var nPos = request.obj.responseText.indexOf(",null]");
	//var massagedReply = request.obj.responseText.substring(0, nPos+6);	
	//eval('r=' + massagedReply + ';');	
	
	return r;	
}

function ajax_error(name, description, number)
{
	this.name = name;
	this.description = description;
	this.number = number;

	return this;
}

ajax_error.prototype.toString = function()
{
	return this.name + " " + this.description;
}

function json_from_object(o)
{
	/*
	if(o == null)
		return 'null';

	switch(typeof(o))
	{
		case 'object':
			if(o.constructor == Array)		// checks if it is an array [,,,]
			{
				var s = '';
				for(var i=0; i<o.length; ++i)
				{
					s += json_from_object(o[i]);

					if(i < o.length -1)
						s += ',';
				}

				return '[' + s + ']';
			}
			break;
		case 'string':
			return '"' + o.replace(/(["\\])/g, '\\$1') + '"';
		default:
			return String(o);
	}
	*/
	
			if(o == null)
			return "null";

		switch(o.constructor) {
		
			case String:
				var s = o; // .encodeURI();
				s = '"' + s.replace(/(["\\])/g, '\\$1') + '"';
				s = s.replace(/\n/g,"\\n");
				s = s.replace(/\r/g,"\\r");
				return s;
		
			case Array:
				var v = [];
				for(var i=0; i<o.length; i++)
					v.push(json_from_object(o[i])) ;
				return "[" + v.join(", ") + "]";
		
			case Number:
				return isFinite(o) ? o.toString() : json_from_object(null);
	
			case Boolean:
				return o.toString();
			
			case Date:
				var d = new Object();
				d.__type = "System.DateTime";
				d.Year = o.getUTCFullYear();
				d.Month = o.getUTCMonth() +1;
				d.Day = o.getUTCDate();
				d.Hour = o.getUTCHours();
				d.Minute = o.getUTCMinutes();
				d.Second = o.getUTCSeconds();
				d.Millisecond = o.getUTCMilliseconds();
				d.TimezoneOffset = o.getTimezoneOffset();
				return json_from_object(d);
	
			default:
				if(o["toJSON"] != null && typeof o["toJSON"] == "function")
					return o.toJSON();
				
				if(typeof o == "object") {
					var v=[];
				
					for(attr in o) {
						if(typeof o[attr] != "function")
							v.push('"' + attr + '": ' + json_from_object(o[attr]));
					}

					if(v.length>0)
						return "{" + v.join(", ") + "}";
					else
						return "{}";		
				}
				return o.toString();
		}
}var ajaxVersion = '5.7.22.2';