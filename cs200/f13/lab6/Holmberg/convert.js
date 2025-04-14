// Purpose of InchesToCentimeters() is to convert inches to centimeters
//
// Created by Kyle Holmberg.
// Last Edited: 10/17/13.
//

// Purpose of InchesToCentimeters(): convert inches to centimeters
function InchesToCentimeters(inches)// number must be in inches                   
// Preconditions: x >= 0
// Postconditions: returns input in centimeters
{
    return (inches * 2.54);
}                               // End of InchesToCentimeters()

// Purpose of CentimetersToInches(): convert centimeters to inches
function CentimetersToInches(cm )// number must be in centimeters
// Preconditions: x >= 0
// Postconditions: returns input in inches
{
    return (cm / 2.54);
}                               // End of CentimetersToInches()

// Purpose of PoundsToKilograms(): convert pounds to kilograms
function PoundsToKilograms(pounds)// number must be in pounds
// Preconditions: x >= 0
// Postconditions: returns input in kilograms
{
    return (pounds / 2.205);
}                               // End of PoundsToKilograms()

// Purpose of KilogramsToPounds(): convert kilograms to pounds
function KilogramsToPounds(kilograms)// number must be in kilograms
// Preconditions: x >= 0
// Postconditions: returns input in pounds
{
    return (kilograms * 2.205);
}                               // End of KilogramsToPounds()

// Purpose of SqFeetToSqMeters(): convert square feet to square meters
function SqFeetToSqMeters(sqfeet)// number must be in square feet
// Preconditions: x >= 0
// Postconditions: returns input in square meters
{
    return (sqfeet / 10.764);
}                               // End of SqFeetToSqMeters()

//Purpose of SqMetersToSqFeet(): convert square meters to square feet
function SqMetersToSqFeet(sqmeters)// number must be in square meters
// Preconditions: x >= 0
// Postconditions: returns input in sqaure feet
{
    return (sqmeters * 10.764);
}                               // End of SqMetersToSqFeet()
