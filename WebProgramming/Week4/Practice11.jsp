   <!--20210815 컴퓨터학과 주현정  -->


<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice11</title>
<style>
	table {
		border : solid 1px #000000;
	}
	
	td {
		padding : 10px;
		width : 90px;
	}
	
	p {
		text-align : center;
		font-size : 35px;
	}
	
</style>
</head>
<body>
	<p>구구단 출력</p>
	<hr>
	<div align = "center">
	<table border ="1">
		<%
			for(int i = 2; i <= 9; i++) {
				if(i == 2 || i == 6) {
					out.println("<tr>");
				}
				
				out.println("<td>");
				for(int j = 1; j <= 9; j++) {
					out.println(i + " * " + j + " = " + i * j +"<br>");
				}
				out.println("</td>");
				if(i == 5 || i == 9) {
					out.println("</tr>");
				}
			}
		%>
	</table>
	</div>
</body>
</html>