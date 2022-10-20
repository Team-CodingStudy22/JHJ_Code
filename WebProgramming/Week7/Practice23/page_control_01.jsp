  <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>page1</title>
<style>
	.green {
		border : 1.5px solid #a4b97f;
		size = "20px"
	}
</style>
</head>
<body>
<form method=post action = page_control_02.jsp>
	아이디 : <input type = "text" name = "username" class = "green">
	비밀번호 : <input type = "password" name = "passwd" class = "green"> 
	<input type = "submit" value ="forward 전송">
</form>
<form method=post action = page_control_03.jsp>
	아이디 : <input type = "text" name = "username" class = "green">
	비밀번호 : <input type = "password"  name = "passwd" class = "green">
	<input type = "submit" value ="sendRedirect 전송">
</form>
</body>
</html>