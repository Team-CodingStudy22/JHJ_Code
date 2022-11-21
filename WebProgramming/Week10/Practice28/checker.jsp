   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("UTF-8"); %>    
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>checker</title>
</head>
<body>
<%
	String action = request.getParameter("action");

	if(action.equals("login")) {
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		
		if(username != null && pwd.equals("hatter")) {
			session.setAttribute("user", username);
		}
	}
	else if(action.equals("logout")){
		session.invalidate();
	}
	
	response.sendRedirect("index.jsp");	
%>
</body>
</html>