   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 18</title>
</head>
<body>
<div align = "center">
	<h2>Include Action Practice</h2>
	<hr>
	<table border = "0">
	<tr>
		<td width = "300">
			<jsp:include page = "calendar.jsp">
				<jsp:param name = "YEAR" value = "2017"/>
				<jsp:param name = "MONTH" value = "10"/>
			</jsp:include>
		</td>
		<td width = "30">&nbsp;&nbsp;&nbsp;</td>
		<td width = "200">
			<jsp:include page = "news.jsp">
				
				<jsp:param name = "TASK2" value = "Homework"/>
			</jsp:include>
		</td>
	</tr>
	</table>
</div>
</body>
</html>