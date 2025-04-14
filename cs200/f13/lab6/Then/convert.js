// Purpose of inToCm(): Convert inches to centimeters
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function inToCm(inches) // number must be in inches
// Preconditions: x >= 0, must be number
// Postconditions: returns input in centimeter form
{
    return (inches * 2.54);
}// end of inToCm()

//=====================================================================================================================

// Purpose of cmToIn(): Convert centimeters to inches
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function cmToIn(cm) // number must be in centimeters
// Preconditions: x >= 0, must be number
// Postconditions: returns input in inch form
{
    return (cm / 2.54);
}// end of cmToIn()

//=====================================================================================================================

// Purpose of lbToKg(): Convert pounds to kilograms
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function lbToKg(lb) // number must be in pounds
// Preconditions: x >= 0, must be number
// Postconditions: returns input in kilogram form
{
    return (lb / 2.205);
}// end of lbToKg()

//=====================================================================================================================

// Purpose of kgToLb(): Convert kilograms to pounds
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function kgToLb(kg) // number must be in kilograms
// Preconditions: x >= 0, must be number
// Postconditions: returns input in pound form
{
    return (kg * 2.205);
}// end of kgToLb()

//=====================================================================================================================

// Purpose of mSqToFtSq(): Convert square meters to square feet
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function mSqToFtSq(mSq) // number must be in sqaure meters
// Preconditions: x >= 0, must be number
// Postconditions: returns input in square feet form
{
    return (mSq / 10.764);
}// end of mSqToFtSq()

//=====================================================================================================================

// Purpose of ftSqToMSq(): Convert square feet to square meters
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function ftSqToMSq(ftSq) // number must be in sqaure feet
// Preconditions: x >= 0, must be number
// Postconditions: returns input in square meters form
{
    return (ftSq * 10.764);
}// end of ftSqToMSq()
