<%-- 컴퓨터학과 20210815 주현정--%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Application Object: 02</title>
</head>
<body>
	<%
	out.println(request.getParameter("username")+"님 환영합니다.<br><br>");
	out.println("세션 ID : " + session.getId() + "<br>");
	
	int interval = Integer.parseInt(request.getParameter("time"));
	session.setMaxInactiveInterval(interval * 60);
	out.println("세션 지속시간 : " + session.getMaxInactiveInterval() +"초");
	out.println("<br><br>");
	
	Integer count = (Integer)application.getAttribute("count");
	if(count == null)
		count = new Integer(0);
	count = count + 1;
	application.setAttribute("count", count);
	
	out.println("오늘의 접속자수: " + count);
	%>
</body>
</html>