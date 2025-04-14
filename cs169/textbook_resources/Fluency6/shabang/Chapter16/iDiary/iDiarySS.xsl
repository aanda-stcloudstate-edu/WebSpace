<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"  
   xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
   
<xsl:template match="idiary">
   <html><head><title>iDiary</title>
         <style>
            body   {background-color : white; font-family : helvetica}
            h1      {text-align : center}
            h2      {text-align : center; color : #993400; margin-bottom:5px; margin-top:8px}
            h3      {margin-bottom:5px; margin-top:8px}
            h4      {margin-bottom:5px; margin-top:8px}
            ul       {margin-left : auto; margin-right : auto; list-style-type : none}
            li.entry { color : black; padding : 10px; border-bottom-style:solid; 
                      border-bottom-width: 0.5px; border-right-style:solid; 
                      border-right-width: 0.5px; margin-bottom : 20px }
            li.date {color : white; position:relative; left : -50px;  background-color : sienna; padding : 8px}
            p        {text-align:center ;}
            a:link {text-decoration: none; color : #993400 }
            a:visited {color :  #993400}
            a:hover {color : #c3bc9a }
         </style>
      </head>
      <body>
         <h1>iDiary: Journal of Interesting Stuff</h1>
            <ul style="max-width:435px">
                  <li style="background-color : sienna; color:white; padding:10px">
                      <i>This is a record of the most interesting 
                      thing I find out each day that's worth 
                      remembering. There's personal stuff in this 
                      database, too, but it's not gonna be displayed! </i>
               </li>
            </ul>
			<ul style="max-width:700px;">
                  <xsl:apply-templates/>
			</ul>
      </body>
   </html>
</xsl:template>

<xsl:template match="entry">
           <xsl:apply-templates/>
</xsl:template>

<xsl:template match="cool">
      	<li class="entry">
           <xsl:apply-templates/>
     	</li>
</xsl:template>

<xsl:template match="date">
   		<li class="date">
    	  <xsl:apply-templates/>
  	    </li>
</xsl:template>

<xsl:template match="title">
   <h2>
      <xsl:apply-templates/>
   </h2>
</xsl:template>

<xsl:template match="quote">
   <blockquote style="background-color : #c89848;
        color:white; padding:10px; font-size:small">
      <xsl:apply-templates/>
   </blockquote>
</xsl:template>

<xsl:template match="link">
   <a href="{@url}"> 
      <b><xsl:apply-templates/></b>
   </a>
</xsl:template>

<xsl:template match="pic">
         <img src="{@file}" width="{@width}"  
                   alt="Picture of Interesting Thing"/> 
</xsl:template>

<xsl:template match="ytvid">
      <br/><br/><iframe width="560" height="315" 
          src="{@file}" frameborder="0" allowfullscreen="1">
      </iframe><br/><br/>
</xsl:template>

<xsl:template match="poem">
      <span style="font-family : century gothic">   
         <xsl:apply-templates/>
      </span>
 </xsl:template>

<xsl:template match="p_title">
   <h3>
        <xsl:apply-templates/>
   </h3>
</xsl:template>

<xsl:template match="poet">
   <h4><i>
       <xsl:apply-templates/>
   </i></h4>
</xsl:template>

<xsl:template match="line">
      <span style="padding-left:{@amt}0px">
          <xsl:apply-templates/>
      <br/></span>
</xsl:template>

<xsl:template match="skip">
      <br/>
</xsl:template>

<xsl:template match="bold">
   <b><xsl:apply-templates/></b>
</xsl:template>

<xsl:template match="ital">
      <i><xsl:apply-templates/></i>
</xsl:template>

<xsl:template match="para">
      <p><xsl:apply-templates/></p>
</xsl:template>

<xsl:template match="personal">
      <!--Display Personal Information -->
      <xsl:apply-templates/>
</xsl:template>

</xsl:stylesheet>
