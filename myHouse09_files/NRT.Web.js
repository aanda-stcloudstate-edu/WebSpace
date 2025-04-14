/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	The functions listed in this file are used by one/more controls in NRT.Web Assmebly
//	So donot forget to include this file in your aspx page
//
//	Copyright : 2005 - 2007, NRT Webservices
//	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
var _nCurrListBoxIndex = -1


function addNRTEvent(obj, evType, fn, useCapture)
{
	if (obj.addEventListener)
	{
		obj.addEventListener(evType, fn, useCapture);
		return true;
	}
	else if (obj.attachEvent)
	{
		var r = obj.attachEvent("on"+evType, fn);
		return r;
	}
	else 
	{
		alert("Handler could not be attached");
	}
}

function GetEventSource(evt)
{
	var ctrlSource;	

	evt = (this.event) ? this.event : evt;
	
	if(evt.srcElement)
	{
		ctrlSource = evt.srcElement;
	}
	else
	{
	    if (typeof evt.target != 'undefined')
	    {
	        ctrlSource = evt.target;
		
		    if (ctrlSource.nodeType == 3)
		    {
			    ctrlSource = ctrlSource.parentNode.previousSibling;
			}
			if ((ctrlSource.nodeType == 1 && ctrlSource.nodeName == 'OPTION') || (ctrlSource.nodeType == 1 && ctrlSource.nodeName == 'option'))
			{
			    ctrlSource = ctrlSource.parentNode;
			}
	    }
	    else
	    {
	        ctrlSource = evt.id;
	    }
	}

	return ctrlSource;
}

/*************************************************************************************
The following functions are used by NRT.Web.Controls.SimpleListBox Control 

Date		Name			Description
--------------------------------------------------------------------------------------
04/09/2007	Ed Glogowski	Added checks for selected values.
**************************************************************************************/
function OnEnterText(textBoxID, listBoxID, evt)
{
	var lstMyList = document.getElementById(listBoxID);
	var txtMyText = document.getElementById(textBoxID);
	
	// Ed Glogowski - 04/09/2007 - Check if there is anything in the text box, if not, don't do anything
	if (txtMyText.value.length > 0)
	{
		for(var x=0; x<lstMyList.length; x++)
		{
			var name = lstMyList.options[x].text;
			name = name.substring(0, txtMyText.value.length);
			if(name.toLowerCase() == txtMyText.value.toLowerCase())
			{
				lstMyList.selectedIndex = x;
				_nCurrListBoxIndex = x;
				break;
			}
		}
	}
	
    if (evt.keyCode==13)
    {
		// Ed Glogowski - 04/09/2007 - Check if there is anything in the text box, if not, don't do anything
		if (txtMyText.value.length > 0)
		{
			OnListBoxSel(textBoxID, listBoxID);
		}
	}
	else if(evt.type=="keyup")
	{
	if (_nCurrListBoxIndex >= 0)
	    {
	    if (lstMyList.options.length >=_nCurrListBoxIndex)
	        {
	        lstMyList.options[_nCurrListBoxIndex].selected = false;
	        }
	    }
	}
	
}

function OnListBoxSel(textBoxID, listBoxID)
{
	var lstMyList = document.getElementById(listBoxID);
	var txtMyText = document.getElementById(textBoxID);
	var hdnSelectedText = document.getElementById(listBoxID + "_hdnSelectedText");
	var hdnSelectedValue = document.getElementById(listBoxID + "_hdnSelectedValue");
	var hdnSelectedIndex = document.getElementById(listBoxID + "_hdnSelectedIndex");		
	
	var idx = lstMyList.selectedIndex;

	if(idx >= 0)
	{
		txtMyText.value = lstMyList.options[idx].text;
		
		if (hdnSelectedText) {
		    hdnSelectedText.value = lstMyList.options[idx].text;		
		}
		if (hdnSelectedValue) {
		    hdnSelectedValue.value = lstMyList.options[idx].value;
		}
		if (hdnSelectedIndex) {
		    hdnSelectedIndex.value = idx;
		}
	}
}

/*************************************************************************************
The following functions are used by NRT.Web.Controls.DoubleListBox Control 

Date		Name			Description
--------------------------------------------------------------------------------------
11/27/2006	Karl Beyer		Updated to support multiple selections in both target and source listboxes.
**************************************************************************************/
function MoveListItem(srcListbox, targetListbox, direction, max, maxErrorText, hdnControl, hdnSelectValues)
{
	var bAdd = false;

	if(srcListbox == null)
		return;

	if(targetListbox == null)
		return;     

	if(max <= 0) 
		bAdd = true;
	else
	{
		if(targetListbox.options.length < max)
			bAdd = true;
		else
		{
			if(maxErrorText != '')
				alert(maxErrorText);                      
			return;
		}
	}
           
	if(bAdd && srcListbox.selectedIndex >= 0)
	{
		var srcListBoxSelectedIndexes = new Array();

        for (var i = 0; i <srcListbox.options.length ; i++)
        {
            if (srcListbox.options[i].selected == true) srcListBoxSelectedIndexes.push(i);
        }

        if (srcListBoxSelectedIndexes.length > 0)
        {
            for (var iterator =0; iterator < srcListBoxSelectedIndexes.length; iterator++)
            {                       
				var val = srcListbox.options[srcListBoxSelectedIndexes[iterator]-iterator].value;
				var txt = srcListbox.options[srcListBoxSelectedIndexes[iterator]-iterator].text;

				srcListbox.options[srcListBoxSelectedIndexes[iterator]-iterator] = null;
				targetListbox.options[targetListbox.length] = new Option (txt, val, false, false);

				if(targetListbox.options.length <= 500)
					SortOptions(targetListbox);

				var resultValue = "";         

				if(direction == "lefttoright")
					resultValue = val + "~" + "R";
				else
					resultValue = val + "~" + "L";

				var leftCompareValue = val + "~" + "L";
				var rightCompareValue = val + "~" + "R";
				var dblItemArray = new Array();

				dblItemArray = hdnControl.value.split(',');                       
				dblItemArray = removeVal(dblItemArray, leftCompareValue);
				dblItemArray = removeVal(dblItemArray, rightCompareValue);
				dblItemArray.push(resultValue);
				hdnControl.value = dblItemArray.toString();
            }

            var rightListBox;

            if(direction == "lefttoright")
                rightListBox = targetListbox;
            else
				rightListBox = srcListbox;

            hdnSelectValues.value = "";

            for(var i=0; i < rightListBox.length; i++) 
                  hdnSelectValues.value += rightListBox.options[i].value + "|";
        }
	}
}

function removeVal(arr, valToRemove)
{
	// Normalize to a string like !val!!val!!val!
	var s = '!' + arr.join('!!') + '!';
	
	// Remove targeted values with delimiters
	s = s.replace(new RegExp('!' + valToRemove + '!', 'g'), '');
  
	// Remove delimiter added to end in step 1
	s = s.replace(/^!/, '');
	
	// Remove delimiter added to start in step 1
	s = s.replace(/!$/, '');
  
	// Convert to array
	return s.split('!!');
}

function DeleteOption(object,index) 
{
    object.options[index] = null;
}

function AddOption(object,text,value) 
{
    var defaultSelected = false;
    var selected = false;
    var optionName = new Option(text, value, defaultSelected, selected)

    object.options[object.length] = optionName;
    object.options[object.length-1].selected = false;
}

function SortOptions(what)
{
    var i = 0;
    var copyOption_length = 0;
    var copyOption = new Array();
    
    for (i=0;i<what.options.length;i++)
        copyOption[i] = new Array(what[i].value,what[i].text);
   
    copyOption_length = i;
    
    // last parm is field to sort on.  0=value 1=text
	MyBubbleSort(copyOption,copyOption_length,1);

    for (var i=what.options.length-1;i>-1;i--)
        DeleteOption(what,i);

    for (var i=0;i<copyOption.length;i++)
        AddOption(what,copyOption[i][1],copyOption[i][0]);
        
}

function MyBubbleSort(arrayName,length,sbyfld) 
{
    for (var i=0; i<(length-1); i++)
    {
        for (var j=i+1; j<length; j++)
        {
            if (arrayName[j][sbyfld] < arrayName[i][sbyfld]) 
            {
                var dummy = arrayName[i][1];
                var dummy2 = arrayName[i][0];
                arrayName[i][1] = arrayName[j][1];
                arrayName[i][0] = arrayName[j][0];
                arrayName[j][1] = dummy;
                arrayName[j][0] = dummy2;
            }
        }
    }
}

function getSortOrder(obj,hdnSelectValues) {
if (obj!=null && obj.options!=null) {
  var orderList = '';
  orderedNodes = obj.getElementsByTagName("OPTION");
  for (var i=0;i < orderedNodes.length;i++) {
    //orderList += orderedNodes[i].getAttribute('value').split(':')[0].value + '|';
    orderList += orderedNodes[i].getAttribute('value') + ':' + parseInt(i+1) + '|';
    }
    hdnSelectValues.value = orderList;
    //debuggingOnly
    //alert(orderList);
  }
}

// -------------------------------------------------------------------
//  hasOptions(obj)
//  Utility function to determine if a select object has an options array
// -------------------------------------------------------------------
function hasOptions(obj) {
	if (obj!=null && obj.options!=null) { return true; }
	return false;
	}

// -------------------------------------------------------------------
//  swapOptions(select_object,option1,option2)
//  Swap positions of two options in a select list
// -------------------------------------------------------------------
function swapOptions(obj,i,j) {
	var o = obj.options;
	var i_selected = o[i].selected;
	var j_selected = o[j].selected;
	var temp = new Option(o[i].text, o[i].value, o[i].defaultSelected, o[i].selected);
	var temp2= new Option(o[j].text, o[j].value, o[j].defaultSelected, o[j].selected);
	o[i] = temp2;
	o[j] = temp;
	o[i].selected = j_selected;
	o[j].selected = i_selected;
	}

// -------------------------------------------------------------------
//  moveOptionUp(select_object)
//  Move selected option in a select list up one
// -------------------------------------------------------------------
function moveOptionUp(obj) {
	if (!hasOptions(obj)) { return; }
	for (i=0; i<obj.options.length; i++) {
		if (obj.options[i].selected) {
			if (i != 0 && !obj.options[i-1].selected) {
				swapOptions(obj,i,i-1);
				obj.options[i-1].selected = true;
				}
			}
		}
	}

// -------------------------------------------------------------------
//  moveOptionDown(select_object)
//  Move selected option in a select list down one
// -------------------------------------------------------------------
function moveOptionDown(obj) {
	if (!hasOptions(obj)) { return; }
	for (i=obj.options.length-1; i>=0; i--) {
		if (obj.options[i].selected) {
			if (i != (obj.options.length-1) && ! obj.options[i+1].selected) {
				swapOptions(obj,i,i+1);
				obj.options[i+1].selected = true;
				}
			}
		}
	}


/*
	**********************************************************************************
		The following functions are used by NRT.Web.Controls.EnhancedTextBox Control 
	**********************************************************************************	
*/

function CountCharText(text_field, countfield, maxlimit)
{ 		
	var content, count;
	
	if (text_field != null)
	{
		content = text_field.innerText;	
	
		//set the count
		count = maxlimit - content.length;
		countDisplay = document.getElementById(countfield);
		if(count < 0)
		{
			text_field.innerText = content.substring(0,maxlimit);
			count=0;
		}
		countDisplay.innerHTML = '(Max. Length ' + maxlimit + ') <SPAN style="font-weight: bold; color: red">' + count + '</SPAN> Characters Remaining';
	}	
}

function CountCharValue(text_field, countfield, maxlimit)
{ 		
	var content, count;
	
	if (text_field != null)
	{
		content = text_field.value;	
	
		//set the count
		count = maxlimit - content.length;
		countDisplay = document.getElementById(countfield);
		if(count < 0)
		{
			text_field.value = content.substring(0,maxlimit);
			count=0;
		}
		countDisplay.innerHTML = '(Max. Length ' + maxlimit + ') <SPAN style="font-weight: bold; color: red">' + count + '</SPAN> Characters Remaining';
	}	
}

/*********************************************************************************************

ALTTXT V1.6
BY: BRIAN GOSSELIN OF SCRIPTASYLUM.COM

INSTRUCTIONS:

1: PUT THESE DIVS IN THE END OF THE BODY AREA:

   <div id="navtxt" class="navtext" style="visibility:hidden; position:absolute; top:0px; left:-400px; z-index:10000; padding:10px"></div>

2: NEXT, PLACE THIS STYLE DECLARATION IN THE HEAD SECTION OF YOUR PAGE (JUST CHANGE YOUR SETTINGS):

   .navtext {
   width:235px;
   font-size:8pt;
   font-family:verdana;
   border-width:2px;
   border-style:outset;
   border-color:#006BAE;
   layer-background-color:#FFF6D9;
   background-color:#FFF6D9;
   color:black;
   }

3: THEN, SET THE 6 SETTINGS BELOW ( dofade, centertext, xoffset, yoffset, mousefollow, and hideDelay ) AS DESIRED.

4: LASTLY ADD THE MOUSEOVER/MOUSEOUT EVENT HANDLERS TO EACH LINK THAT YOU WANT THIS EFFECT FOR:

     EXAMPLE: <a href="scriptasylum.com" onmouseover="writetxt('Popup text')" onmouseout="writetxt(0)">Link text</a>

NOTES:

  > YOU CAN CAUSE A BOX *NOT* TO DISAPPEAR ONCE THE MOUSE LEAVES THE LINK BY SIMPLY OMITTING THE
    onmouseout="writetxt(0)" PART. THIS WILL CAUSE THE CURRENT BOX TO REMAIN VISIBLE. THIS IS BEST
    USED WHEN mousefollow MODE IS DISABLED (SET TO false).

  > YOU CAN SET THE PADDING STYLE ATTRIBUTE *ONLY* IN THE navtxt DIV ITSELF AND *NOT* IN THE STYLE
    SHEET AT THE TOP OF THE PAGE. OTHERWISE NS4 DISPLAYS SOME WEIRD BEHAVIOR. ALSO, THE PADDING ATTRIBUTE
    ONLY HAS AN EFFECT IN IE4+ AND NS6+.

*********************************************************************************************/

var dofade=true;       // ENABLES FADE-IN EFFECT (FOR IE4+ AND NS6 ONLY)

var centertext=false;  // CENTERS THE TEXT INSIDE THE BOX. YOU CAN'T SIMPLY DO THIS VIA "STYLE" BECAUSE OF NS4.
                       // OTHERWISE, TEXT IS LEFT-JUSTIFIED.

var xoffset=9;         // HORIZONTAL PIXEL COUNT FROM CURSOR

var yoffset=25;        // VERTICAL PIXEL COUNT FROM CURSOR

var mousefollow=true; // ENABLES MOUSE FOLLOW MODE WHERE THE BOX CONTINUES TO FOLLOW THE MOUSE.  TO false TO
                       // LOCK THE BOX WHEREVER IT INITIALLY APPEARS.

var hideDelay=300;     // DELAY IN MILLISECONDS ( 1 SECOND = 1000 MILLISECONDS) FROM WHEN YOU HOVER OUT OF LINK
                       // AND THE BOX DISAPPEARS ONLY WHEN "mousefollow" IS SET TO "false".
                       // THIS WILL GIVE THE USER TIME TO CLICK A LINK OR WHATEVER IN THE BOX BEFORE IT DISAPPEARS.

function altProps()
{
	this.w3c=(document.getElementById)?true:false;
	this.ns4=(document.layers)?true:false;
	this.ie4=(document.all && !this.w3c)?true:false;
	this.ie5=(document.all && this.w3c)?true:false;
	this.ns6=(this.w3c && navigator.appName.indexOf("Netscape")>=0 )?true:false;
	this.w_y=0;
	this.w_x=0;
	this.navtxt=null;
	this.boxheight=0;
	this.boxwidth=0;
	this.ishover=false;
	this.ieop=0;
	this.op_id=0;
	this.oktomove=false;
	this.dy=0;
}

var AT=new altProps();

function toggle_centertext()
{
	centertext=!centertext;
}

function toggle_mousefollow()
{
	mousefollow=!mousefollow;
}

function toggle_dofade()
{
	dofade=!dofade;
	if(!dofade)AT.ieop=100;
}

function getwindowdims()
{
	AT.w_y=(AT.ie5||AT.ie4)?document.body.clientHeight:window.innerHeight;
	AT.w_x=(AT.ie5||AT.ie4)?document.body.clientWidth:window.innerWidth;
}

function getboxwidth()
{
	if(AT.ns4)
	{
		AT.boxwidth=(AT.navtxt.document.width)? AT.navtxt.document.width : AT.navtxt.clip.width;
	}
	else if(AT.ie4)
	{
		if(AT.navtxt != null && AT.navtxt.style != null)
		{
			AT.boxwidth=(AT.navtxt.style.pixelWidth)? AT.navtxt.style.pixelWidth : AT.navtxt.offsetWidth;
		}
	}
	else
	{
		if(AT.navtxt != null && AT.navtxt.style != null)
		{
			AT.boxwidth=(AT.navtxt.style.width)? parseInt(AT.navtxt.style.width) : parseInt(AT.navtxt.offsetWidth);
		}
	 }
}

function getboxheight()
{
	if(AT.ns4)
	{
		AT.boxheight=(AT.navtxt.document.height)? AT.navtxt.document.height : AT.navtxt.clip.height;
	}
	else if(AT.ie4)
	{
		if(AT.navtxt != null && AT.navtxt.style != null)
		{
			AT.boxheight=(AT.navtxt.style.pixelHeight)? AT.navtxt.style.pixelHeight : AT.navtxt.offsetHeight;
		}
	}
	else
	{
		if(AT.navtxt != null && AT.navtxt.style != null)
		{		
			AT.boxheight=parseInt(AT.navtxt.offsetHeight);
		}
	 }
}

function movenavtxt(x,y)
{
	if(AT.ns4)AT.navtxt.moveTo(x,y);
	else
	{
		if(AT.navtxt != null && AT.navtxt.style != null)
		{
			AT.navtxt.style.left=x+'px';
			AT.navtxt.style.top=y+'px';
		}
	}
}

function getpagescrolly()
{
	if(AT.ie5||AT.ie4)return document.body.scrollTop;
	else return window.pageYOffset;
}

function getpagescrollx()
{
	if(AT.ie5||AT.ie4)return document.body.scrollLeft;
	else return window.pageXOffset;
}

function writeindiv(text)
{
	if(AT.ns4){
	AT.navtxt.document.open();
	AT.navtxt.document.write(text);
	AT.navtxt.document.close();
	}
	else
	{
		if(AT != null && AT.navtxt != null)
			AT.navtxt.innerHTML=text;
	}
}

function writetxt(text)
{
	if(dofade && (AT.ie4||AT.w3c))clearInterval(AT.op_id);
	if(text!=0)
	{
		if(!mousefollow)clearTimeout(AT.dy);
		AT.oktomove=true;
		AT.ishover=true;
		if(AT.ns4)text='<div class="navtext">'+((centertext)?'<center>':'')+text+((centertext)?'</center>':'')+'</div>';
		if(AT.w3c||AT.ie4){
			if(AT.navtxt != null && AT.navtxt.style != null){
				AT.navtxt.style.textAlign=(centertext)?"center":"left";
			}
		}
		writeindiv(text);
		if(AT.ns4)AT.navtxt.visibility="show";
		else{
			if(AT.navtxt != null && AT.navtxt.style != null)
			{
				AT.navtxt.style.visibility="visible";
				AT.navtxt.style.display="block";
			}
		}
		getboxheight();
		if((AT.w3c||AT.ie4) && dofade)
		{
			if(AT.ie4||AT.ie5)
			{
				if(AT.navtxt != null && AT.navtxt.style != null)
					AT.navtxt.style.filter="alpha(opacity=0)";
			}
			if(AT.ns6)AT.navtxt.style.MozOpacity=0;
			AT.ieop=0;
			AT.op_id=setInterval('incropacity()',50);
		}
	}
	else
	{
		if(mousefollow)hideAlttxt();
		else AT.dy=setTimeout('hideAlttxt()',hideDelay);
	}
}

function hideAlttxt()
{
	if(AT.ns4)AT.navtxt.visibility="hide";
	else{
		if(AT.navtxt != null && AT.navtxt.style != null)
		{
			AT.navtxt.style.display="none";
			AT.navtxt.style.visibility="hidden";
		}
	}
	movenavtxt(-AT.boxwidth-10,0);
	writeindiv('');
}

function incropacity()
{
	if(AT.ieop<=100)
	{
		AT.ieop+=7;
		if(AT.navtxt != null && AT.navtxt.style != null)
		{
			if(AT.ie4||AT.ie5)
				AT.navtxt.style.filter="alpha(opacity="+AT.ieop+")";
			if(AT.ns6)
				AT.navtxt.style.MozOpacity=AT.ieop/100;
		}
	}
	else
		clearInterval(AT.op_id);
}

function moveobj(evt)
{
	mx=(AT.ie5||AT.ie4)?event.clientX:evt.pageX;
	my=(AT.ie5||AT.ie4)?event.clientY:evt.pageY;
	if(AT.ishover && AT.oktomove){
	margin=(AT.ie4||AT.ie5)?5:25;
	if(AT.ns6)if(document.height+27-window.innerHeight<0)margin=15;
	if(AT.ns4)if(document.height-window.innerHeight<0)margin=10;
	if(AT.ns4||AT.ns6)mx-=getpagescrollx();
	if(AT.ns4)my-=getpagescrolly();
	xoff=mx+xoffset;
	yoff=(my+AT.boxheight+yoffset-((AT.ns6)?getpagescrolly():0)>=AT.w_y)? -5-AT.boxheight-yoffset: yoffset;
	movenavtxt( Math.min(AT.w_x-AT.boxwidth-margin , Math.max(2,xoff))+getpagescrollx(), my+yoff+((!AT.ns6)?getpagescrolly():0));
	if(!mousefollow)AT.oktomove=false;}
}

//var old_window_onload = (window.onload) ? window.onload :  function(){};
//window.onload = function(){old_window_onload();InitializeATOnLoad();}
//window.attachEvent("onload", InitializeATOnLoad)
//Changed to addNRTEvent for better cross-browser support - Chad Boettcher 11/22/2006
addNRTEvent(window, "load", InitializeATOnLoad, false);

function InitializeATOnLoad()
{
  AT.navtxt=(AT.ns4)?document.layers['navtxt']:(AT.ie4)?document.all['navtxt']:(AT.w3c)?document.getElementById('navtxt'):null;
  if(AT.navtxt != null)
  {
	getboxwidth();
	getboxheight();
	getwindowdims();
	if(AT.ie4||AT.ie5&&dofade)AT.navtxt.style.filter="alpha(opacity=100)";
	AT.navtxt.onmouseover=function(){
	if(!mousefollow)clearTimeout(AT.dy);
	}
	AT.navtxt.onmouseout=function(){
	if(!mousefollow)AT.dy=setTimeout('hideAlttxt()',hideDelay);
	}
	if(AT.ns4)document.captureEvents(Event.MOUSEMOVE);
	document.onmousemove=moveobj;
	window.onresize=getwindowdims;
  }	
}

/*
	**********************************************************************************
		The following functions are common to all webpages
	**********************************************************************************	
*/

function ConfirmOfficeChange(lstBox)
{
    if (confirm("Are you sure you want to switch offices? \n If you haven't clicked the submit button \n you'll lose any changes to this office.")) 
    {
		location.href = "officeprofile.aspx?OfficeID=" + lstBox.options[lstBox.selectedIndex].value;
    }
}

function ConfirmDelete(message, url)
{
    if (confirm(message)) 
		location.href = url;
}

function CalculateIFrameHeight(frameID)
{
	var the_height=document.getElementById(frameID).contentWindow.document.body.scrollHeight;	//find the height of the internal page
	var the_width=document.getElementById(frameID).contentWindow.document.body.scrollWidth;		//find the width of the internal page
	
	document.getElementById(frameID).style.height=the_height;	//change the height of the iframe
	document.getElementById(frameID).style.width=the_width;		//change the width of the iframe
}

/* **********************************************************************************
		Enable/disable checkBox items
	
		checkboxlistID = id of the checkboxlist
		chkarray = array of indexes to set enable or disable
		disable = true to disable
   **********************************************************************************
*/
function EnableDisableListItems(checkBoxListId, chkArray, disable)
{
	// Get the checkboxlist object.
	objCtrl = document.getElementById(checkBoxListId);
	
	// Does the checkboxlist not exist?
	if(objCtrl == null)		
        return;

	var i = 0;
	
	// iterate through listitems that need to be enabled or disabled
	for(i = 0; i<chkArray.length; i++)
	{
		objItem = document.getElementById(checkBoxListId + '_' + chkArray[i]);

		if(objItem == null)
			continue;

		// Disable/Enable the checkbox.
		objItem.disabled = disable;	
	}
}

function ShowTextBox(textBoxID)
{
	document.getElementById(textBoxID).style.display= "block";
}

function HideTextBoxOnDropdownIndexChange(textBoxID, dropdownList)
{			
	if(dropdownList.selectedIndex > 0)
	{
		document.getElementById(textBoxID).value = "";
		document.getElementById(textBoxID).style.display= "none";
	}
}
function ResetDropdown(dropdownID)
{
	document.getElementById(dropdownID).selectedIndex = 0;
}

function showPopupWindow(popupURL, popupTitle, windowWidth, windowHeight, showToolbar, isResizable, otherFeatures) {
	var winRef; // Scratch Variable
	
	if (windowWidth != '') {
		if (otherFeatures != '') otherFeatures = otherFeatures + ',';
		otherFeatures = otherFeatures + 'width=' + windowWidth; 
	}
		
	if (windowHeight != '') {
		if (otherFeatures != '') otherFeatures = otherFeatures + ',';
		otherFeatures = otherFeatures + 'height=' + windowHeight; 
	}

	// The default of showing toolbar is true so only set if sent false
	if  (!Boolean(showToolbar)) {
		if (otherFeatures != '') otherFeatures = otherFeatures + ',';
		otherFeatures = otherFeatures + 'toolbar=no'; 
	}
	
	// The default of resize is true so only set if sent false
	if (!Boolean(isResizable)) {
		if (otherFeatures != '') otherFeatures = otherFeatures + ',';
		otherFeatures = otherFeatures + 'resizable=no'; 
	}
	
	winRef = window.open(popupURL, popupTitle, otherFeatures);
}

function ShowHideLinksListPanel(panelID, linkControl)
{
	var panel = document.getElementById(panelID);
	
	if(panel.style.display == 'block')
	{
		linkControl.innerText = "Show Links";
		panel.style.display = 'none';
	}
	else
	{
		linkControl.innerText = "Hide Links";
		panel.style.display = 'block';
	}
}

/* Module specific */
function ValidateCategoryName(source, arguments)
{
	var dropdown = document.getElementById('ddlCategory');
	var textBox = document.getElementById('txtCategoryName');
	
	if(dropdown.selectedIndex == 0 && textBox.value.length == 0)
		arguments.IsValid = false;
	else
		arguments.IsValid = true;
}


// **********************************************************************************
//		function switch_photo
//	
//		Rotates photos, URLS, Text for the PhotoRotator custom control.
//   **********************************************************************************

function switch_photo(oControlName, oRotatingLinkType, oRotatingTextType)
 {
	//If this evaluates to false, don't switch the images.
	//This was done so that multiple photo rotators on the same page can be set to switch at different times
	//rather all changing at the same time.
	if (this.eval(oControlName + '_PhotoPathArray')[this.eval(oControlName + '_ValueArray')[0]] != null)
	{
	
		var imgObj = document.getElementById(oControlName + '_imgPhotoRotation');
		imgObj.style.filter = 'blendTrans(duration=2)';
		imgObj.style.filter = 'blendTrans(duration=crossFadeDuration)';
		
		if (imgObj.filters)
			{
			imgObj.filters.item(0).Apply();
			}
		imgObj.src =  this.eval(oControlName + '_PhotoPathArray')[this.eval(oControlName + '_ValueArray')[0]];
		if (imgObj.filters)
			{
			imgObj.filters.item(0).Play();
			}
			
		// Set Rotating Links
		if ((oRotatingLinkType == '1') || (oRotatingLinkType == '2'))
			{			  
				var linkObj = document.getElementById(oControlName + '_hlPhotos');
				linkObj.href = this.eval(oControlName + '_PhotoLinkArray')[this.eval(oControlName + '_ValueArray')[0]];
				
				//var testlink = this.eval(oControlName + '_PhotoLinkArray')[this.eval(oControlName + '_ValueArray')[0]];

				if (this.eval(oControlName + '_PhotoIsUrlExternal')[this.eval(oControlName + '_ValueArray')[0]] == 'True')
						linkObj.target = 'New';
				else
						linkObj.target = '_top';				
											
				if (linkObj.href == '')
					{
						linkObj.href = 'javascript:void(0);'
						linkObj.disabled=1;
					}
				else
						linkObj.disabled=0;
							
			}
			
		// Set Rotating Text
		if ((oRotatingTextType == '1') || (oRotatingTextType == '2') || (oRotatingTextType == '3'))
			//  PhotoRotator2_TextPrimary
			{			
				var txtObj = document.getElementById(oControlName + '_TextPrimary');
				txtObj.innerHTML = this.eval(oControlName + '_PhotoTextPrimaryArray')[this.eval(oControlName + '_ValueArray')[0]];
			}
			
		if (oRotatingTextType == '3')	
			{
				var imgObj2 = document.getElementById(oControlName + '_imgSecondaryPhotoRotation');
					imgObj2.style.filter = 'blendTrans(duration=2)';
					imgObj2.style.filter = 'blendTrans(duration=crossFadeDuration)';
				if (imgObj2.filters)
					{
					imgObj2.filters.item(0).Apply();
					}
				imgObj2.src =  this.eval(oControlName + '_PhotoSecondaryPathArray')[this.eval(oControlName + '_ValueArray')[0]];
				if (imgObj2.filters)
					{
					imgObj2.filters.item(0).Play();
					}
			}		
	}
	this.eval(oControlName + '_ValueArray')[0]++;
	if (this.eval(oControlName + '_ValueArray')[0] == this.eval(oControlName + '_ValueArray')[1])
		{	
			this.eval(oControlName + '_ValueArray')[0] = 0;
		}
 }
 

/*********************************************************
Functions for Meta Tag Administration
*********************************************************/

function toggle(node) 
{
	var nextDIV = node.parentNode.parentNode.parentNode.parentNode.nextSibling;
	
	while(nextDIV != null && nextDIV.nodeName == "DIV") 
	{
		if (nextDIV.style.display == 'none') 
		{
			nextDIV.style.display = 'block';	
			
			if(node.childNodes.item(0).nodeName == "#text")
				node.childNodes.item(1).src = getImgDirectory(node.childNodes.item(1).src) + "minus.gif";
			else
				node.childNodes.item(0).src = getImgDirectory(node.childNodes.item(0).src) + "minus.gif";				
		}
		else
		{
			nextDIV.style.display = 'none';
			
			if(node.childNodes.item(0).nodeName == "#text")
				node.childNodes.item(1).src = getImgDirectory(node.childNodes.item(1).src) + "plus.gif";
			else
				node.childNodes.item(0).src = getImgDirectory(node.childNodes.item(0).src) + "plus.gif";				
		}
		
		nextDIV = nextDIV.nextSibling;		
	}		
}

function getImgDirectory(source) 
{
    return source.substring(0, source.lastIndexOf('/') + 1);
}

var divReadOnly;
var divEdit;	
var txtArea;
var divEditLink;
var divUpdCancelLink;

function MetaTagAdmin_SetControlState(menuItemID, controlID, mode)
{
	divReadOnly = document.getElementById("div_readonly_" + menuItemID + controlID);		
	divEdit = document.getElementById("div_" + menuItemID + controlID);	
	txtArea = document.getElementById("txt_" + menuItemID + controlID);
	divEditLink = document.getElementById("div_EditLink_" + menuItemID);	
	divUpdCancelLink = document.getElementById("div_UpdateCancelLink_" + menuItemID);		
	
	// Edit
	if(mode == 0)
	{
		divEdit.style.display = "inline";
		txtArea.value = divReadOnly.innerText;
		divReadOnly.style.display = "none";	
		divEditLink.style.display = "none";	
		divUpdCancelLink.style.display = "inline";							
	}
	// Cancel
	else if(mode == 1)
	{
		divEdit.style.display = "none";
		txtArea.innerText = "";
		divReadOnly.style.display = "inline";		
		divEditLink.style.display = "inline";	
		divUpdCancelLink.style.display = "none";					
	}
	// Update
	else if(mode == 2)
	{
		divReadOnly.innerText = txtArea.innerText;
		divReadOnly.style.display = "inline";		
			
		divEdit.style.display = "none";
		txtArea.innerText = "";
	
		divEditLink.style.display = "inline";	
		divUpdCancelLink.style.display = "none";					
	}	
}

function MetaTagAdmin_Edit(menuItemID)
{	
	MetaTagAdmin_SetControlState(menuItemID, "_BrowserTitle", 0);
	MetaTagAdmin_SetControlState(menuItemID, "_MetaDescription", 0);
	MetaTagAdmin_SetControlState(menuItemID, "_MetaKeywords", 0);			
}

function MetaTagAdmin_Update(menuItemID, pageID)
{
	var sTitle = document.getElementById("txt_" + menuItemID + "_BrowserTitle").value;
	var sDesc = document.getElementById("txt_" + menuItemID + "_MetaDescription").value;
	var sKeywords = document.getElementById("txt_" + menuItemID + "_MetaKeywords").value;
	
	var pageID = MetaTagController.UpdateMetaTagData(menuItemID, pageID, sTitle, sDesc, sKeywords).value;	
	if(pageID != 0)
	{
		MetaTagAdmin_SetControlState(menuItemID, "_BrowserTitle", 2);
		MetaTagAdmin_SetControlState(menuItemID, "_MetaDescription", 2);
		MetaTagAdmin_SetControlState(menuItemID, "_MetaKeywords", 2);				
	}
	else
	{
		MetaTagAdmin_Cancel(menuItemID);
	}
	
}

function MetaTagAdmin_Cancel(menuItemID)
{
	MetaTagAdmin_SetControlState(menuItemID, "_BrowserTitle", 1);
	MetaTagAdmin_SetControlState(menuItemID, "_MetaDescription", 1);
	MetaTagAdmin_SetControlState(menuItemID, "_MetaKeywords", 1);	
}

function SwapImage(imgName, evt)
{
	evt = (window.event) ? window.event : evt;	
	target = (window.event) ? evt.srcElement: evt.target;	
	
	target.src = imgName;
}