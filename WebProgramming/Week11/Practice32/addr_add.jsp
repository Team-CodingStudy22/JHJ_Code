<%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.pr32.*"%>
<!DOCTYPE html>
<%
request.setCharacterEncoding("UTF-8");
%>
<jsp:useBean id="addr" class="jspbook.pr32.AddrBean" />
<jsp:setProperty name="addr" property="*" />
<jsp:useBean id="am" class="jspbook.pr32.AddrManager" scope="application" />
<%
	am.add(addr);
%>
<html>
<head>
<meta charset="UTF-8">
<title>add</title>
</head>
<body>
<div align="center">
<h2>등록내용</h2>
<%String [] groupName = {"가족", "친구", "직장"}; %>
이름 : <%=addr.getUsername() %><p>
전화번호 : <%=addr.getTel() %><p>
이메일 : <%=addr.getEmail() %><p>
성별 : <%=addr.getGender() %><p>
그룹 : <%=groupName[addr.getGroup()] %>
<hr>
<a href="addr_list.jsp">전체 목록 보기</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="addr_list_group.jsp">그룹별 목록 보기</a>
</div>
</body>
</html>