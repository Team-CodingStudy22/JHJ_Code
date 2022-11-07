<%-- 컴퓨터학과 20210815 주현정--%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Session Object: 02</title>
</head>
<body>
	<%
	out.println(request.getParameter("username")+"님 환영합니다.<br><br>");
	out.println("세션 ID : " + session.getId() + "<br>");
	out.println("세션 지속시간(default) : " + session.getMaxInactiveInterval() +"초");
	%>
	<br><br>
	<a href="session_03.jsp">session_03.jsp로 가기</a>
</body>
</html>