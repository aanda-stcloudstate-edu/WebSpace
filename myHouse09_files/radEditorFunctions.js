
//CSV 
//These functions to clean up test pasted in from word.
//These remove the font face, size, color, table, and other tags we don't want.
//implement them on the page with the following code, replacing the radEditorContainer name as necessary:
	//var editor = document.getElementById("radEditorContainerStaticContent1myREText");
	//if (editor){
	//editor.attachEvent("onpaste",handlePaste);
	//}
	
//***************** NOTE: If any tags are added to the stripTags function,
//***************** they should be copied to this same function in the "Web" project, 
//***************** (Unless the tags are permitted on the dynamic content pages.)
function stripTags(whichField)
{
var Word
var newWord
Word = document.getElementById(whichField).innerHTML;
newWord = DelHTML(Word, "<FONT")
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</FONT");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<font")
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</font");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<SPAN");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</SPAN");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<span");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</span");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<H");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</H");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<h");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</h");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<?xml");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<o:");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</o:");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<table");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</table");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<tbody");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</tbody");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<tr");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</tr");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<td");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</td");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<TABLE");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</TABLE");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<TBODY");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</TBODY");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<TR");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</TR");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<TD");   
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</TD");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<a");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "<A");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</a");
if (newWord.length > 0) 
newWord = DelHTML(newWord, "</A");

document.getElementById(whichField).innerHTML = newWord; 
}

function DelHTML(HTMLWord,testTag)
{
HTMLlen = HTMLWord.length;

var a = 0
var Word
Word = HTMLWord
while (a != -1) {
	//location of tag start and end
	a = HTMLWord.indexOf(testTag);
	bstart = a + 1
	if (a == -1)
        break;

	b = HTMLWord.indexOf(">", bstart);  
	
	//get all text before the tag
	c = HTMLWord.substring(0, a);
	if(b == -1) b = a;
	
	//get text after the tag
	d = HTMLWord.substring((b + 1), HTMLlen);
	//concatonate the text before and after the tag, to remove the tag
	if (testTag.indexOf("SPAN") > 0 ){
	HTMLWord = c + " " + d;
	} else {
	HTMLWord = c + d;
	}
}
	Word = HTMLWord
return Word
}



// CSV 
//This function counts the inntertext characters of radeditor if they go over limit. 
//It does NOT count the HTML characters because the user never sees those characters. 
//That's why the database field is so much larger than this limit.
function countRADChar(whichField, countField, maxChars)
	{ 		
		var content;
		var allContent;
		var count;
		var endSearchLoc;
		var sendmessage;
		sendmessage = ""
		
		content = document.getElementById(whichField).innerText;	
		content = content.replace("&nbsp;"," ")
		allContent = document.getElementById(whichField).innerHTML;	
		allContent = allContent.replace("&nbsp;"," ")
		endSearchLoc = allContent.length
		
		//set the count, based on the inner text without the HTML tags
		count = maxChars - content.length;
		countDisplay = document.getElementById(countField);
		if(count < 0)
			//delete non-html characters until the count is back to zero.
			{
				sendmessage = "You have exceeded the " + maxChars + " character limit."
				//start searching at the end of the string
				endSearchLoc = allContent.length - 1
				while (count < 0) {
					var x;
					var testChar;
					var a;
					var b;
					//Does the content segment end with a tag or text?
					testChar = endSearchLoc
					if (allContent.charAt(endSearchLoc) != ">") {
						//Last character is not part of a tag, delete it.
						a = allContent.substring(0,endSearchLoc);
						b = allContent.substring(endSearchLoc + 1,allContent.length);
						allContent = a + b;
						count = count + 1;
						endSearchLoc = endSearchLoc - 1 
					} else {
						//The last character is the end of an HTML tag. Find the beginning of that tag.
						x = allContent.lastIndexOf("<", endSearchLoc);
						testChar = allContent.substring(x,endSearchLoc)
						//The character in front of the tag will be searched next.
						endSearchLoc = x - 1
					}
				}
				document.getElementById(whichField).innerHTML = allContent;
				//alert the user that they're over the character limit.
				if (sendmessage != "") {
					alert(sendmessage);
				}
				//Needs to be blurred. 
				//If texted was pasted in the middle, and deleted at the end cursor gets kicked to the end and confuse the user.
			document.getElementById(whichField).blur
			}
			countDisplay.innerHTML = '(Max. Length ' + maxChars + ') <SPAN style="font-weight: bold; color: red">' + count + '</SPAN> Characters Remaining';		
	}	



		

