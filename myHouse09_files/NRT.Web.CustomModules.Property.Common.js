
function TransferToPage(pagePath, homeSearchAlertID)
{	
	var response;
	
	if(spm_browserType() == "ie")
		response = SearchController.PersistInCache(SearchXml.xml);
	else
		response = SearchController.PersistInCache(SearchXml.childNodes[0].xml);
	
	if(pagePath.indexOf("?") >= 0)
		pagePath += "&";
	else
		pagePath += "?";
	
	if(homeSearchAlertID != null)
		pagePath += "SearchID=" + response.value + "&HomeSearchAlertID=" + homeSearchAlertID;
	else
		pagePath += "SearchID=" + response.value;		

		window.document.location = pagePath;
}

function ClearCheckBox(chkboxName)
{
	var chkBox = document.getElementById(chkboxName);
	
	var rExp = new RegExp(" ", "g");	
	if(this.event.srcElement.value.replace(rExp, '') == '')
		chkBox.checked = true;
	else
		chkBox.checked = false;
}

function CheckCheckBox(textboxName)
{
	var txtBox = document.getElementById(textboxName);	
	
	var rExp = new RegExp(" ", "g");		
	if(txtBox.value.replace(rExp, '') == '')
		this.event.srcElement.checked = true;	
}

function InitializeMap(regionID, countyID, showMappointLink, areaName, StateID)
{
	var script = null;
	var sLinkDisplay = showMappointLink ? "inline" : "none";
	var sCityLinkDisplay = "none";
	var sCitySomeLinkDisplay = "none";
	
	window.parent.document.getElementById('divRightHeaderText_City').style.display =  "none"; 
	window.parent.document.getElementById('divRightHeaderText_City_Some').style.display =  "none"; 
	window.parent.document.getElementById('divSpaceholder').style.display =  "inline"; 
		
	
	if(areaName == null)
		areaName = '0';
	
	if(regionID == 0 && countyID == 0 && areaName == '0' )
	{
	 	sCityLinkDisplay = 'none';
	 	sCitySomeLinkDisplay = 'none';
	 	}
	 else
	 {
	 	sCityLinkDisplay = 'inline';
	 	sCitySomeLinkDisplay = 'none';
	 }
		
	script = "window.parent.document.getElementById('divSpaceholder').style.display = 'none';window.parent.document.getElementById('divRightHeaderText_City_Some').style.display = '" + sCitySomeLinkDisplay + "';window.parent.document.getElementById('divRightHeaderText_City').style.display = '" + sCityLinkDisplay + "';window.parent.document.getElementById('div_CitySearch_MapPointLink').style.display = '" + sLinkDisplay + "';window.parent.LoadCities(" + regionID + ", " + countyID + ", '" + areaName + "', " + StateID + ");";
	
//	document.getElementById('hlRightHeaderText_City_Some').onclick = "window.parent.LoadCities(" + regionID + ", " + countyID + ", '" + areaName + "', " + StateID + ");"
 //window.parent.document.getElementById('hlRightHeaderText_City_Some').onclick = "window.parent.LoadCities(" + regionID + ", " + countyID + ",'" + areaName + "', " + StateID + ");"

window.parent.document.getElementById("hlRightHeaderText_City_Some").onclick = function(){
window.parent.document.getElementById('divRightHeaderText_City_Some').style.display = 'none'; 
window.parent.document.getElementById('divRightHeaderText_City').style.display = 'inline';
window.parent.LoadCities(regionID,countyID,areaName,StateID); 
}
 
 
	if(window.status != "complete") 
		setTimeout(script, 1000);
	else
		setTimeout(script, 1);
}

function LoadMap(propertyGUID, address, city, state, zip)
{
	var sMapLink = DetailController.GetMapPointMap(propertyGUID, address, city, state, zip).value;
	window.open(sMapLink, null, 'width=800, height=600');
}
