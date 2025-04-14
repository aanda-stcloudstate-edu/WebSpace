function DewPoint(temperature, humidity)
{
	var dpt; 
	dpt=temperature-((100-humidity)/2.778); 
	return dpt; 
}

function WindChill(temperature, wind)
{
	var wch; 
	wch=35.74+(0.6215*temperature)+(((0.4275*temperature)-35.75)*Math.pow(wind, 0.16)); 
	return wch; 
}
