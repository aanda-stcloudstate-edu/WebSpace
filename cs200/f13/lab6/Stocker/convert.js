//File: convert.js
//Author: Janna Stocker
//
//Functions for converting metric units & english units.
///////////////////////////////////////////////////////////////////////////

function InchesToCentimetres(inches)
//Assume: inches is a distance, measured in inches
//Returns: the corresponding distance in centimetres
{
	var cm;
	
	cm = inches * 2.54;
	return cm;
}

function CentimetresToInches(cm)
//Assume: cm is a distance, measured in centimetres
//Returns: the corresponding distance in inches
{
	var inches;
	
	inches = cm / 2.54;
	return inches;
}

function KilogramsToPounds(kg)
//Assume: kilograms is a weight, measured in kilograms
//Returns: the corresponding weight in pounds
{
	var pounds;
	
	pounds = kg * 2.205;
	return pounds;
}

function PoundsToKilograms(pounds)
//Assume: pounds is a weight, measured in pounds
//Return: the corresponding weight in kilograms
{
	var kg;
	
	kg = pounds / 2.205;
	return kg;
}

function SquaremetersToSquarefeet (sqM)
//Assume: square meters is an area, measured in square meters
//Return: the corresponding area in square feet
{
	var squareFeet;
	
	squareFeet = sqM * 10.764;
	return squareFeet;
}

function SquarefeetToSquaremeters (sqft)
//Assume: square feet is an area, measured in square feet
//Return: the corresponding area in square meters
{
	var squareMeters;
	
	squareMeters = sqft / 10.764;
	return squareMeters;
}
