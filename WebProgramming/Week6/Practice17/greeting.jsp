 <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>greeting message</title>
<style>
	p {
		font-size : 25px;
	}
	
</style>
</head>
<body>
<p>greeting.jsp에서 출력한 메시지입니다.</p>

<%
	out.println(request.getParameter("name") + "님 환영합니다.<br>");
	out.println("오늘은 " + request.getParameter("date") + "입니다.");
%>

</body>
</html>