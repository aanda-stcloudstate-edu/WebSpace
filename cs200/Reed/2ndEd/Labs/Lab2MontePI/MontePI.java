// MontePI.java
// Dave Reed    davereed@creighton.edu
//
// This applet is used in a Web page to estimate the value of PI
// using a Monte Carlo method.
//////////////////////////////////////////////////////////////////

import java.awt.*;
import java.applet.*;
import java.util.Random;
import netscape.javascript.JSObject;                 

/**
 * This class draws random points in and around a circle.
 */
public class MontePI extends Applet
{
	private static Random randy;
	private int SIZE;
	private Image offScreenImage;
	private Graphics offScreenGraphics;
	
	private JSObject pageInside, pageTotal;
	private int numInside, numTotal;
	
	private double distance(double x1, double y1, double x2, double y2)
	{
		return Math.sqrt(Math.pow(x1-x2, 2) + Math.pow(y1-y2, 2));	
	}
	
	public void init()
	{
		randy = new Random();
		Dimension dim = getSize();
		SIZE = Math.min(dim.width, dim.height);
		
		try {
			JSObject jsWin = JSObject.getWindow(this);      			
			JSObject jsDoc = (JSObject) jsWin.getMember("document");  
			JSObject MonteForm = (JSObject) jsDoc.getMember("MontePI"); 
			pageInside = (JSObject) MonteForm.getMember("numInside");   
			pageTotal = (JSObject) MonteForm.getMember("totalPoints");
		}
		catch (netscape.javascript.JSException jse) {  }

		drawCircle();
	}
	
	public void drawCircle()
	{
		numInside = 0;  numTotal = 0;
       	pageInside.setMember("value", "0");
        pageTotal.setMember("value", "0");
		
		offScreenImage = createImage(SIZE, SIZE);
	    offScreenGraphics = offScreenImage.getGraphics();
		Graphics g = getGraphics();
		
		offScreenGraphics.clearRect(0,0,SIZE,SIZE);
		g.clearRect(0,0,SIZE,SIZE);
		
	    offScreenGraphics.setColor(Color.red);
        g.setColor(Color.red);
	    offScreenGraphics.fillOval(0, 0, SIZE, SIZE);
        g.fillOval(0, 0, SIZE, SIZE);
	}
	
	public void drawDots(int numDots)
    {
        Graphics g = getGraphics();
 		 
        double x, y;
        int pixX, pixY;
        for (int i = 0; i < numDots; i++) {
        	x = Math.random() * SIZE;
            y = Math.random() * SIZE;
         
        	numTotal++;
        	if (distance(x, y, SIZE/2.0, SIZE/2.0) <= SIZE/2.0) {
            	offScreenGraphics.setColor(Color.white);
            	g.setColor(Color.white);
		    	numInside++;
        	}
        	else {
            	offScreenGraphics.setColor(Color.black);
            	g.setColor(Color.black);
        	}
 		
			pixX = (int)Math.round(x);
			pixY = (int)Math.round(y);
			offScreenGraphics.drawLine(pixX, pixY, pixX, pixY);
        	g.drawLine(pixX, pixY, pixX, pixY);
        	
        	pageInside.setMember("value", ""+numInside);
        	pageTotal.setMember("value", ""+numTotal);
        
    	}
    }
	
	public void paint(Graphics g)
	{
		g.drawImage(offScreenImage, 0, 0, null);
	}
}
