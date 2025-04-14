
var _imgMainPhoto = document.getElementById("imgMainPhoto");
var _imgStartSlideShow	= document.getElementById("imgStartSlideShow");
var _imgStopSlideShow	= document.getElementById("imgStopSlideShow");
var _nTimerID = -1;

function LoadMainPhoto(photoUrl)
{	
	_imgMainPhoto.src = photoUrl;		
}

function RunSlideShow(photoArrayIndex)
{
	try
	{
		if(oTransContainer.filters) // IE Only
			oTransContainer.filters[0].Apply();
	}
	catch(e){}
	
	var nNextIndex = photoArrayIndex + 1;
	
	if(nNextIndex > _aPhotoArray.length - 1)
		nNextIndex = 0;	
	
	//LoadMainPhoto(_aPhotoArray[nNextIndex]);
	ShowNewPhoto('add');
	
	try
	{
	if(oTransContainer.filters)
		oTransContainer.filters[0].Play();		
	}
	catch(e){}
	
	// If first time, then immediately show the first photo
	_nTimerID = setTimeout("RunSlideShow(" + nNextIndex + ");ToggleslideShowButton(true);", 3000);	
}

function StopSlideShow()
{
	if(_nTimerID != -1)
	{
		clearTimeout(_nTimerID);
		ToggleslideShowButton(false)
	}
}

function ToggleslideShowButton(start)
{
	if(start)
	{
		 _imgStartSlideShow.style.display='none';
		 _imgStopSlideShow.style.display='inline'
	}
	else
	{
		_imgStartSlideShow.style.display='inline';
		 _imgStopSlideShow.style.display='none'
	}
}

function PrintAllPhotos()
{
	window.frames["ifrmPrint"].focus();
	window.frames["ifrmPrint"].print();
}

this.document.body.onkeyup = function()
{
	// Do Speed Search when "Enter" key is pressed
	if(event.keyCode == 13)
	{
		ProcessSpeedSearch('/CustomModules/Property/PropertyResults.aspx?SearchType=1');
		event.cancelBubble = true;		
	}	
}

/*
function LoadMap(propertyGUID, address, city, state, zip)
{
	var sMapLink = DetailController.GetMapPointMap(propertyGUID, address, city, state, zip).value;
	window.open(sMapLink, null, 'width=800, height=600');
}
*/
