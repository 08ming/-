// JavaScript Document
var count = 0;
var counttd = 100;
var countbt = 1000;
var flag = 0;
var a = 0;

function add() {
    document.getElementById("inputbox").style.display = 'block';
}

function aadd() {
    var s1 = document.getElementById("s1").value;
    var s2 = document.getElementById("s2").value;
    var s3 = document.getElementById("s3").value;
    document.getElementById("inputbox").style.display = 'none';
    var tr = document.getElementById("info");
    tr.innerHTML += "<tr id='" + count + "' align='center'>" + "<td>" + s1 + "</td>" + "<td id='" + counttd + "'>" + s2 + "</td>" + "<td>" + s3 + "</td>" + '<td><input type="button" value="删除" οnclick="delet(' + count + ')" />&nbsp<input id="' + countbt + '"  type="button" value="修改" οnclick=\"change(' + counttd + ',' + countbt + ')" /></td>' + "</tr>";
    count++;
    counttd++;
    countbt++;
    flag = 0; //让flagc重新等于0 否则会一直累加 下面flag==0//==1就无法判断
}

function delet(count) {
    var row = document.getElementById(count);
    row.remove(count);                                    //删除id为count的行数据
}

function change(counttd, countbt) {//传递两个参数，counttd是点击修改后将td变为input，countbt是点击修改后将button的value改为确定


    if (flag == 0) {
        var td = document.getElementById(counttd);
        td.innerText = null;                       //将td的内容变为空
        var input = document.createElement("input"); //第一次点击修改时，在td里增加一个input
        input.id = a;                               //给input一个id
        td.appendChild(input);                      //将input添加到td节点下
        var bt = document.getElementById(countbt);
        bt.value = "确定";                           //将修改按钮改为确定
    }
    if (flag == 1) {                            //第二次点击修改按钮
        var a = document.getElementById(a);    //或缺增加的input的id
        a.style.display = 'none';                //使input隐藏
        var td = document.getElementById(counttd); //获取要修改的td的id
        td.innerText = a.value;                 //将input中输入的value赋给td
        var bt = document.getElementById(countbt); //获取button的id
        bt.value = "修改";                       //将确定按钮改为修改
    }

    flag++;    //按一次修改按钮就+1


}
