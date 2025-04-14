// File: rectangle.js
// Author: Janna Stocker
//
// This file contains several functions for creating and working with a box.
/////////////////////////////////////////////////////////////////////////////
function
IsPointInRectangle()
// Given : an x & y coordinate are input by user
// Returns : message of inside or outside box
{   var left, right, top, bottom, XCoord, YCoord;

        left = parseFloat(document.getElementById('leftBox').value);
	    right = parseFloat(document.getElementById('rightBox').value);
	    top = parseFloat(document.getElementById('topBox').value);
	    bottom = parseFloat(document.getElementById('bottomBox').value);
	    XCoord = parseFloat(document.getElementById('xBox').value);
	    YCoord = parseFloat(document.getElementById('yBox').value);
		
	if (document.getElementById('toggleBorderBox').value == 'The box border is inside the box.' && XCoord == right || document.getElementById('toggleBorderBox').value == 'The box border is inside the box.' && XCoord == left)
		{return insideRec = document.getElementById('outputDiv').innerHTML=
		 'The point (' + XCoord + ',' + YCoord + ') is inside the box.';}	
		 
	    else if (document.getElementById('toggleBorderBox').value == 'The box border is inside the box.' && YCoord == top || document.getElementById('toggleBorderBox').value == 'The box border is inside the box.' && YCoord == bottom)
		{return insideRec = document.getElementById('outputDiv').innerHTML=
		 'The point (' + XCoord + ',' + YCoord + ') is inside the box.';}
		 
        else if (XCoord > left && XCoord < right && YCoord < top && YCoord > bottom)
		{return insideRec = document.getElementById('outputDiv').innerHTML=
		 'The point (' + XCoord + ',' + YCoord + ') is inside the box.';}
		
	if (XCoord <= left || XCoord >= right || YCoord >= top || YCoord <= bottom)
	    {return outsideRec = document.getElementById('outputDiv').innerHTML=
		 'The point (' + XCoord + ',' + YCoord + ') is outside the box.';}   
}

function
BoundariesAreIn()
// Given : an x & y coordinate are input by user
// Returns : message of including border as inside or outside of box
{
	var left, right, top, bottom, XCoord, YCoord;
	
	if (document.getElementById('toggleBorderBox').value == 'The box border is outside the box.')
	    {
		return BorderInside = document.getElementById('toggleBorderBox').value=
		 'The box border is inside the box.';
	    }
		
	if (document.getElementById('toggleBorderBox').value == 'The box border is inside the box.')
		{
		return BorderOutside = document.getElementById('toggleBorderBox').value=
		 'The box border is outside the box.';
		}
}

function
OrientationString()
// Given : an x & y coordinate are input by user
// Returns : message of incorrect or unusable coordinates
{
	var left, right, top, bottom, XCoord, YCoord, Horizontal, Vertical;

        left = parseFloat(document.getElementById('leftBox').value);
	    right = parseFloat(document.getElementById('rightBox').value);
	    top = parseFloat(document.getElementById('topBox').value);
	    bottom = parseFloat(document.getElementById('bottomBox').value);
	    XCoord = parseFloat(document.getElementById('xBox').value);
	    YCoord = parseFloat(document.getElementById('yBox').value);
		
		Horizontal = left < right;
		Vertical = top > bottom;
	
	if (!Horizontal && !Vertical)
		{
		return Alert = document.getElementById('outputDiv').innerHTML=
		 'The Vertical & Horizontal box coordinates are bad.';
		}
	
		else if (!Horizontal)
		{
		return HorizontalAlert = document.getElementById('outputDiv').innerHTML=
		 'The Horizontal box coordinates are bad.';
		}
		
		else if (!Vertical)
		{
		return VerticalAlert = document.getElementById('outputDiv').innerHTML=
		 'The Vertical box coordinates are bad.';
		}
}
