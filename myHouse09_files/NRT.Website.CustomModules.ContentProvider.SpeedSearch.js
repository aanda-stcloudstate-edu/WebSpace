

// EG 4/11/07 - Removed to only do Speed search on return in edit box
//this.document.body.onkeydown = function(e)
//{	
//	if(e==null)
//		e = event;
//
//	if(e.keyCode == 13)
//	{
//		// By default do Speed Search when "Enter" key is pressed and if there is any text in the SS textbox
//		if(document.getElementById(GetObjectID("txtSearchInput")).value.length > 0)
//		{
//			ProcessSpeedSearch();
//		}
//		// Otherwise see if the parent page supports our Interface (i.e) the paret page shud have a hidden control called
//		//	"hdnDefaultEnterKeyFunction"
//		else
//		{		
//			var hdnDefaultEnterKeyFunction = document.getElementById("hdnDefaultEnterKeyFunction");			
//			
//			if(hdnDefaultEnterKeyFunction != null)
//				eval(hdnDefaultEnterKeyFunction.value);
//		}
//	}	
//}

// EG 4/11/07 - Added to Do Perform Speed Searches
function PerformSpeedSearch(e)
{	
  //  evt = window.event
   // alert(e.keyCode);
    if (e.keyCode==13)
    {
		// By default do Speed Search when "Enter" key is pressed and if there is any text in the SS textbox
		if(document.getElementById(GetObjectID("txtSearchInput")).value.length > 0)
		{
			ProcessSpeedSearch(e);
		}
		// Otherwise see if the parent page supports our Interface (i.e) the paret page shud have a hidden control called
		//	"hdnDefaultEnterKeyFunction"
		else
		{		
			var hdnDefaultEnterKeyFunction = document.getElementById("hdnDefaultEnterKeyFunction");			
			
			if(hdnDefaultEnterKeyFunction != null)
				eval(hdnDefaultEnterKeyFunction.value);
		}
	}	
}

String.prototype.trim = function(trimChar)
{
	var rExpBegin = new RegExp("^" + trimChar + "+", "g");
	var rExpEnd = new RegExp(trimChar + "+$", "g");
	
	return this.replace(rExpBegin, '').replace(rExpEnd, '')
}


function setCursor() 
{ 
	var hdnDefaultCursorControl = document.getElementById("hdnDefaultCursorControl");	
	var ctrl = null;
	
	if(hdnDefaultCursorControl != null && hdnDefaultCursorControl.value != '')
		ctrl = document.getElementById(hdnDefaultCursorControl.value);		
	else
		ctrl = document.getElementById(GetObjectID("txtSearchInput"));
	
	if(ctrl != null)
		ctrl.focus(); 
}

function ChangeInfoText()
{
	var ddlSearchType = document.getElementById(GetObjectID("ddlSearchType"));
	var divSearchTypeInfoText = document.getElementById("divSearchTypeInfoText");
	var divSearchTypeInfoText2 = document.getElementById("divSearchTypeInfoText2");	
	
	switch(ddlSearchType.selectedIndex)
	{
		case 0:
		{
			divSearchTypeInfoText.innerHTML = "Enter MLS #";
			divSearchTypeInfoText2.style.display = "inline";
			break;
		}
		case 1:
		{
			divSearchTypeInfoText.innerHTML = "Enter House # and / or Street Name";
			divSearchTypeInfoText2.style.display = "none";			
			break;
		}
		case 2:
		{ 
			divSearchTypeInfoText.innerHTML = "Enter Home InfoLine / Text ID";
			divSearchTypeInfoText2.style.display = "inline";			
			break;
		}						
	}
}

function ProcessSpeedSearch(evt)
{
	var txtSearchInput = document.getElementById(GetObjectID("txtSearchInput"));
	var ddlSearchType = document.getElementById(GetObjectID("ddlSearchType"));
	var resultPageUrl = document.getElementById("hdnResultsUrl").value;
	
	var sInput = txtSearchInput.value;
	sInput = sInput.trim(' ');
	
	if(sInput.length > 0)
	{
		// If searched on MLS# or HomeInfoLine#, validate if the input is a number
		if(ddlSearchType.selectedIndex == 1 || ContentController.IsNumber(sInput).value)
		{		
			var redirectUrl = resultPageUrl + "&SearchID=" + ddlSearchType.selectedIndex + "&SearchValue=" + ContentController.UrlEncode(sInput).value;		
			window.location.href = redirectUrl;
		}
	}
	
	//event.cancelBubble = true;
	//event.returnValue = false;
	evt.cancelBubble = true;
	evt.returnValue = false;
	return false;
}

function GetObjectID(objName)
{
	if(spm_browserType() == "ie")
		var dummyControl = document.getElementById("divDummy").childNodes[0];	
	else
		var dummyControl = document.getElementById("divDummy").childNodes[1];	
		
	return dummyControl.id.substr(0, dummyControl.id.lastIndexOf("_")) + "_" + objName;
}
