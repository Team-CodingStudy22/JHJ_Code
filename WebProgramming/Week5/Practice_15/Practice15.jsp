   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import= "java.util.Calendar"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice15</title>

</head>
<body>
<%
	int year = 1919;
	int month = 3;
	
	Calendar cal = Calendar.getInstance();
	cal.set(year, month - 1, 1);
	int startDay = cal.get(Calendar.DAY_OF_WEEK);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	
	int i;
	int j = startDay;
	out.println("<H2>" + year +"년 " + month + "월" + "</H2><HR>");
	
	for(i = 0; i < startDay - 1; i++) {
		out.print("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
	}
	
	for(i = 1; i <= end; i++) {
		out.print(i + "&nbsp;&nbsp;&nbsp;&nbsp;");
		if(j % 7 == 0) 
			out.print("<br>");
		
		j++;
	}
%>
</body>
</html>