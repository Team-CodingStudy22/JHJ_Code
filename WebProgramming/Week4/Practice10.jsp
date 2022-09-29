   <!--20210815 컴퓨터학과 주현정  -->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice10</title>
<style>
	table {
		border : solid 1px #000000;
		text-align : center;
		font-size : 15px;
	}
	td {
		width : 70px;
	}
	
	#Sun {
		color : #EA3323;
	}
	#Sat {
		color : #0000F5;
	}
</style>
</head>
<body>
<div align = "center">
<table border = "1" width = "700" height = "200">
<%
	String[] day = {"일", "월", "화", "수", "목", "금", "토"};

	for(int i = 0; i < 5; i++) {
		out.println("<tr>");
		if(i == 0) {
			for(int j = 0; j < 7; j++) {
				if(j == 0)
					out.println("<td id = 'Sun'>"+day[j]+"</td>");
				else if(j == 6)
					out.println("<td id = 'Sat'>"+day[j]+"</td>");
				else
					out.println("<td>"+day[j]+"</td>");				
			}

		}
		else{
			for(int j = 0; j < 7; j++) {
				out.println("<td> &nbsp; </td>");
			}	
		}
		out.println("</tr>");
	}
%>
</table>
</div>
</body>
</html>