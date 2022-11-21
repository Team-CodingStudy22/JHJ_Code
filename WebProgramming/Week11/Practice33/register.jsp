<%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.pr33.*"%>
<% request.setCharacterEncoding("UTF-8"); %>
<jsp:useBean id="login" class="jspbook.pr33.LoginBean" scope="page" />
<jsp:setProperty name="login" property="*" />
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>register</title>
<style>
	table {
		border: 0;
		text-align : center;
	}
	tr {
		height : 40px;
	}
</style>
</head>
<body>
<div align="center">
	<h1>등록내용</h1>
	<table border="0">
		<tr><td>이름 : <%=login.getId() %></td></tr>
		<tr><td>패스워드 : <%=login.getPw() %></td></tr>
		<tr><td>이메일 : <%=login.getEmail() %></td></tr>
		<tr><td>성별 : <%=login.getGender() %></td></tr>
		<tr><td>생일 : <%=login.getBirth() %></td></tr>
	</table>
	<hr>
<%
	out.println(login.getId() + "씨는 ");
	if(login.getGender() == 1)
		out.println("여성이고, ");
	else
		out.println("남성이고, ");
	
	if(login.isGrownUp())
		out.println("성인입니다.");
	else
		out.println("성인이 아닙니다.");
%>
</div>
	
</body>
</html>