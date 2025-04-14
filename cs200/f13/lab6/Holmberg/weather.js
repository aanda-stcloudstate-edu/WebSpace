// Created by Kyle Holmberg
// Last edited: 10/17/13

// Purpose of DewPoint(): Calculate the dew point
function DewPoint(temp, humidity)
// Preconditions: must be a number
// Postconditions: returns dew point
{
    return (temp - ((100 - humidity) / 2.778));
}                                           // End of DewPoint()

// Purpose of WindChill(): Calculate the wind chill
function WindChill(temp, wind)
// Preconditions: wind >= 0, must be numbers
// Postconditions: returns wind chill
{
    return (35.74 + (.6215 * temp) + ((.4275 * temp) - 35.75) * (Math.pow(wind, .16)));
}                                           // End of WindChill()
