   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import ="java.util.Calendar" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice14</title>
</head>
<body>
<%
	Calendar cal = Calendar.getInstance();

	int year = cal.get(Calendar.YEAR);
	int month = cal.get(Calendar.MONTH);
	int date = cal.get(Calendar.DATE);
	int day = cal.get(Calendar.DAY_OF_WEEK);
	
	String[] days = {"일", "월", "화", "수", "목", "금", "토"};
	String day_name = days[day - 1];
	
	int start = cal.getMinimum(Calendar.DATE);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	
	out.println("오늘은 " + year + "년 " + (month+1) + "월 " + date + "일 " + day_name + "요일입니다.<br><br>" );
	out.println("이번 달은 " + start + "일부터 시작하여 " + end + "일에 끝납니다.<br><br>");
	
	cal.set(2002, Calendar.APRIL, 18);
	int day2 = cal.get(Calendar.DAY_OF_WEEK);
	String day_name2 = days[day2-1];
	out.println("내 생일 " + cal.get(Calendar.YEAR) + "년 " + (cal.get(Calendar.MONTH)+1) + "월 " + cal.get(Calendar.DATE) + "일은 " + day_name2+ "요일입니다.<br><br>" );
%>
</body>
</html>