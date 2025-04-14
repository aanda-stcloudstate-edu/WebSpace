/*********************************************************
Functions for Dynamic Page Link Groups
*********************************************************/

function mover(text) {

	var object = '';
	var dhtml = 'IE'; //This only works for the admin site
    if (document.layers) {
        eval('document.layers["' + object + 'b"].moveBelow(document.layers["' + object + 'a"])');
        eval('document.layers["' + object + 'b"].visibility="hide"');
        eval('document.layers["' + object + 'a"].visibility="show"');
    }
    else {
		if (dhtml == 'IE') {
			object= "rollovertext";
			eval(object + '.innerHTML = text');
		}else {
			object= "rollovertext";
			document.getElementById(object).innerHTML = text;
		}
    }
}

function mout(text) {
	var object = "rollovertext";
	var dhtml = 'IE'; //This only works for the admin site
	text="&nbsp;";
	
    if (document.layers) {
        eval('document.layers["' + object + 'a"].moveBelow(document.layers["' + object + 'b"])');
        eval('document.layers["' + object + 'a"].visibility="hide"');
        eval('document.layers["' + object + 'b"].visibility="show"');
    }
    else {
 		if (dhtml == 'IE') {
			eval(object + '.innerHTML = text');
		}else {
			document.getElementById(object).innerHTML = text;
		}
    }
}

function buildRolloverTextArea() {
	var strContent = ''

	if (document.layers) {
		strContent += '<ilayer width=\"100%\" id=rollovertext>\n" + "<layer width=\"100%\" id=rollovertextarea>';
	} else {
		strContent += '<div id=\"rollovertext\" name=\"rollovertext\">&nbsp;';
	}

	if (document.layers) {
		strContent +='&nbsp;</layer>\n</ilayer>';
 	} else {
  	strContent += '</div>';	
	}
  document.write(strContent)
}



function newWindow(sUrl, nHeight, nWidth, bMenu)
{
var myWin;
	var sFeatures = "height=" + nHeight + ",width=" + nWidth + ",resizable"
	if(bMenu == 1) sFeatures += ",location,menubar,scrollbars,status,toolbar"
	myWin = window.open(sUrl, "LinkedWindow" + sUrl , sFeatures);
}

function newWindowWName(sUrl, sWinName, nHeight, nWidth, bMenu)
{
	var sFeatures = "height=" + nHeight + ",width=" + nWidth + ",resizable,scrollbars"
	if(bMenu == 1) sFeatures += ",location,menubar,status,toolbar"
	window.open(sUrl, sWinName ,sFeatures)
}