   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList"%>
<!DOCTYPE html>
<%

	request.setCharacterEncoding("UTF-8"); 
		
	String username = request.getParameter("name");
	String usernum = request.getParameter("phone");
	
	if(username != null)
		session.setAttribute("user", username);
	if(usernum != null)
		session.setAttribute("userphone", usernum);
%>    
<html>
<head>
<meta charset="UTF-8">
<title>add</title>
<style>
OL {
	text-align:left;
	width: 160px;
  	margin-left: auto;
  	margin-right: auto;
}
</style>
</head>
<body>
<div align="center">
<p><h1>주소록</h1></p>
<hr>
<%	
	username = (String)session.getAttribute("user");
	usernum = (String)session.getAttribute("userphone");
	
	ArrayList<String>addrbook = (ArrayList<String>)application.getAttribute("addrbook");

	if(addrbook == null) 
		addrbook = new ArrayList<String>();
	addrbook.add(username +", " + usernum);
	application.setAttribute("addrbook", addrbook);
	
	if(addrbook != null) {
		out.println("<OL class='ol'>");
		for(String addrbooks : addrbook) 
			out.println("<LI>" + addrbooks + "</LI>");
		out.println("</OL>");
	}
%>
</div>
</body>
</html>