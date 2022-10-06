   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" isErrorPage="true"%>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>notice</title>
    <style>
        table {
            border : none;
            text-align: center;
            font-family: "굴림", Gulim, Arial, sans-serif;
            font-weight: bolder;
        }

        
        .orange {
            background-color: #F5D8BA;
            border: none;
            width : 600px;
            height: 40px;
        }

        .yellow {
            background-color: #FCEFD8;
            border: none;
            height: 300px;
        }
        
        p {
           font-size: 25px;
            font-weight: 500;
        }
    </style>
</head>
<body>
    <div align = "center">
       <img src = "image/eclass_title.jpg">
        <table border="0">
           <form name = "frm4">
            <tr>
                <td class = "orange">오류가 발생했습니다</td>
            </tr>
            
            <tr>
               <td class = "yellow">
                   <img src = "image/flower.gif">
                   <br><br>
                   오류 발생시간 : <%=new java.util.Date() %>
                   <br><br>최대한 빨리 조치하겠습니다.
                </td>   
            </tr>
            </form>
        </table>
    </div>
</body>
</html>