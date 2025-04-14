// Purpose of dewPoint(): Calculate the dew point
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function dewPoint(temp, humidity)
// Preconditions: inputs  must be number
// Postconditions: returns the dew point
{
    return (temp - ((100 - humidity)/2.778));
}// end of dewPoint()

//=====================================================================================================================

// Purpose of windChill(): Calculates the wind chill
//
// Created by Mitchell Then.
// Last Edited: 10/17/13.
//
function windChill(temp, wind)
// Preconditions: inputs must be number, wind speed must be >= 0
// Postconditions: returns the wind chill
{
    return (35.74 + (0.6215 * temp) + (((0.4275 * temp) - 35.75) * Math.pow(wind, 0.16)));
}// end of windChill()
