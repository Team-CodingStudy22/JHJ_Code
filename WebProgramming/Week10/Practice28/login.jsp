   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>login</title>
</head>
<body>
	<form action="checker.jsp" method=post>
	<%
		String username = (String)session.getAttribute("user");
		
		if(username == null) {
			out.println("아이디 : " + "<input type='text' name='username'><br><br>");
			out.println("패스워드 : " + "<input type='text' name='pwd'><br><br>");
			out.println("<input type='hidden' name='action' value='login'> ");
			out.println("<input type='submit' value='로그인'>");
		}
		else {
			out.println(username+"님 환영합니다.<br><Br>");
			out.println("<input type='hidden' name='action' value='logout'> ");
			out.println("<input type='submit' value='로그아웃'>");
		}
	%>
	</form>
</body>
</html>