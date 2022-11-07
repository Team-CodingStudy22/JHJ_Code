<%-- 컴퓨터학과 20210815 주현정--%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Application Object: 01</title>
<style>
#num1 {
	border: 0px;
	width: 115px;
}
</style>
</head>
<body>
	<form method = post action = "application_02.jsp">
		아이디 : <input type=text id=num1><input type=text name="username"><br>
		원하는 세션 지속시간 (분) : <input type=text name="time"><br><br>
		<% application.setAttribute("count", 1); %>
		<input type=submit value="로그인">
		<input type="button" value = "취소">
	</form>
</body>
</html>