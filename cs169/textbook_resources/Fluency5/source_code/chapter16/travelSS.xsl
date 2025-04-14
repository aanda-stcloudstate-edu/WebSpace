<?xml version="1.0" encoding="utf-8" ?>
<xsl:stylesheet version="1.0"
   xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="travels">
   <html >
      <head><title>Travelogue</title>
           <meta http-equiv="Content-Type" 
                      content="text/html; charset=utf-8"/>
        <style type="text/css">
           body {background-color : black; color : white; 
                    font-family : helvetica}
        </style>
      </head>
      <body>
         <h2>Places I've Traveled</h2>
            <table>
               <xsl:apply-templates/>
            </table>
      </body>
   </html>
</xsl:template>

<xsl:template match="country">
   <tr>
      <xsl:apply-templates/>
   </tr>
</xsl:template>

<xsl:template match="name">
   <td style="text-align : center">
      <xsl:apply-templates/><br/>
         <img src="{@flag}"  alt="Country Flag"/> 
   </td>
</xsl:template>

<xsl:template match="tour">
   <td>
      <xsl:apply-templates/>
   </td>
</xsl:template>

<xsl:template match="sight">
   <br/><xsl:apply-templates/>
</xsl:template>

</xsl:stylesheet>
