//File: weather.js
//Author: Janna Stocker
//
// functions for figuring dew point & wind chill
/////////////////////////////////////////////////////////////////////////////////

function DewPoint(humidity, temperature)
     // Assumes: the humidity is a percentage between 0 - 100 & temperature is in Fahrenheit
     // Results: displays the dew point for the user after inputs for temp & humidity are entered in outputDiv
     {
		var humidity, temperature, dewP, dewPRound;
		
	    humidity = parseFloat(document.getElementById('humidityBox').value);
		temperature = parseFloat(document.getElementById('temperatureBox').value);
		dewP = temperature - ((100-humidity)/2.778);
		dewPRound = Math.round(dewP*100)/100
		
		return dewPRound;
	 }

function WindChill(temp, wind)
	//Assumes:the wind is in mph and the temperature is in Fahrenheit
	//Results: displays the wind chill for the user after inputs are entered in outputDiv
	{
		var temp, wind, windChill, windChillR;
		
		temp = parseFloat(document.getElementById('temperatureBox').value);
		wind = parseFloat(document.getElementById('windBox').value);
		windChill = 35.74+0.6215*temp+(0.4275*temp-35.75)*Math.pow(wind,0.16)
		windChillR = Math.round(windChill*100)/100
		
		return windChillR;
	}
