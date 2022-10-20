  <%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>login</title>
    <style>
        table {
            border : none;
            text-align: left;
        }
        
        .write {
            background-color: #FCFCA4;
            border: none;
            box-shadow: 1.5px 1.5px #8c8c8b inset;
        }
        
        p {
           font-size: 25px;
            font-weight: bold;
        }
        
        .font1 {
            font-size: 13px;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <div align = "center">
       <img src = "image/eclass_title.jpg">
         <p>로그인</p>
        <hr width = "100%">
            <form name = "frm1" method=post action=result.jsp>
        <table border="0">
            <tr>
                <td rowspan="5">
                    <img src = "image/eclass_logo.png">
                </td>
                <td colspan="2" class = "font1">회원님의 아이디와 비밀번호를 정확히 입력하세요.</td>
            </tr>
            

            <tr>
               <td></td>
                <td>
                    <select name = "type">
                        <option value = "학부생" selected>학부생</option>
                        <option value = "대학원생">대학원생</option>
                        <option value = "교직원">교직원</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td class = "font1">아이디 </td>
                <td>   
                <input type = "text" class = "write" name = "strID"></td>
            </tr>
            
            <tr>
                <td class = "font1">비밀번호 </td>
                <td>  
                <input type = "password" class = "write" name ="strPwd"></td>
            </tr>
            
            <tr>
               <td colspan="2">
                    <input type = "submit" value = "로그인">
                    <input type = "button" value = "가입하기">
                </td>
            </tr>
        </table>
        </form>
    </div>
</body>
</html>