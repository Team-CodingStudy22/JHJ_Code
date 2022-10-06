   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice12</title>
<style>
	table {
		font-family: "굴림", Gulim, Arial, sans-serif;
		font-weight: bold;
	}
	
</style>
</head>
<body>
<div align = "center">
<H1><p>include 지시어 연습</p></H1>
<HR>
<table border = "0">
	<tr>
		<td><%@ include file="calendar.jsp" %></td>
		<td width = "10">&nbsp;&nbsp;&nbsp;</td>
		<td width = "400"><%@ include file="news.jsp" %></td>
	</tr>
</table>
</div>
</body>
</html>