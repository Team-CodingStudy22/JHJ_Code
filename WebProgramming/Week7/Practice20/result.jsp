  <%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import = "java.util.Enumeration" %>
    <% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>result</title>
</head>
<body>
	<h1>전달된 파라미터 이름들</h1>
	<br>
<%
	Enumeration<String> names = request.getParameterNames();
	while(names.hasMoreElements()) {
		String s = names.nextElement();
		out.println(s + "<br>");
	}
	out.println("<hr>");
	out.println("타입 : " + request.getParameter("type"));
	out.println("<br>아이디 : " + request.getParameter("strID"));
	out.println("<br>패스워드 : " + request.getParameter("strPwd"));
%>
	 
</body>
</html>