<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"  
   xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="idiary">

   <html><head><title>iDiary</title>
         <style type="text/css">
            body  {background-color : white; font-family : helvetica}
            h1      {text-align : center}
            h2      {text-align : center; color : #993400}
            ul      {margin-left : auto; margin-right : auto; list-style-type : none}
         </style>
      </head>
      <body>
         <h1 style="color : black">iDiary: Journal of Interesting Stuff</h1>
            <ul style="max-width:435px">
                  <li style="background-color : #c3bc9a; color:white; padding:10px">
                      <i>This is a record of the most interesting 
                      thing I found out each day that's worth 
                      remembering. There's personal stuff in this 
                      database, too, but it's not gonna be displayed! 
                      </i>
               </li>
            </ul><br/>
			<ul style="max-width:700px;">
                  <xsl:apply-templates/>
			</ul>
      </body>
   </html>

</xsl:template>

<xsl:template match="entry">
           <xsl:apply-templates/>
</xsl:template>

</xsl:stylesheet>

