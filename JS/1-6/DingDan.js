// JavaScript Document
var count = new Array();
function del(number){
	var temp =  document.getElementById(number).rowIndex;
	var tab = document.getElementById("t");
	tab.deleteRow(temp);
}

function addRow(){

	 var currentRows = document.getElementById("t").rows.length-1; 
	  var insertTr = document.getElementById("t").insertRow(currentRows);
	  var insertTd = insertTr.insertCell(0);
	 insertTd.style.textAlign = "center";
	 insertTd.innerHTML = "数据处理";

	 insertTd = insertTr.insertCell(1);
	 insertTd.style.textAlign="center";
	 insertTd.innerHTML = "10";

	 insertTd = insertTr.insertCell(2);
	 insertTd.style.textAlign="center";
	 insertTd.innerHTML = "￥30";

	 insertTd = insertTr.insertCell(3);
	 insertTd.style.textAlign="center";
	 count[currentRows] = 0;
	 var actionid = insertTr.id = ""+currentRows;

	 insertTd.innerHTML = "<button onClick = \"del('"+actionid+"')\">删除</button> <button id ='btn"+currentRows+"'       onClick=\"EditRow('"+actionid+"')\">修改</button>";

	/*var btn = document.createElement("button");
	btn.onclick = del(actionid);
	insertTr.appendChild(btn);*/

	//insertTd.click = del(insertTd.id);

 }

function addLast(){
	var temp = document.getElementById("lastRow").nextElementSibling;
	temp.innerHTML="<tr id='lastRow'><td colspan='4'><div style='text-align: center'><button name='提交订单'\ onClick='test()'>提交订单</button></div></td></tr>";
}

function EditRow(countid){
	
	var id = parseInt(countid);
	//alert(count[id]);
	var tr = document.getElementById(countid);
	if(count[id] % 2 == 0){
		
		var td = tr.cells[0];
		td.innerText = null;
		var input = document.createElement("input");
		input.id = 'a';
		td.appendChild(input);
		
		td = tr.cells[1];
		td.innerText = null;
		input = document.createElement("input");
		input.maxLength = 2;
		input.id = 'b';
		td.appendChild(input);
		
		td = tr.cells[2];
		td.innerText = null;
		input = document.createElement("input");
		input.id = 'c';
		td.appendChild(input);
		
		var bt = document.getElementById("btn"+countid);
		bt.innerHTML="确定";
		count[id] = 1;
		
	}
	else{
		
		var a = document.getElementById('a');    //或缺增加的input的id
        a.style.display = 'none';                //使input隐藏
        td = tr.cells[0]; //获取要修改的td的id


        td.innerText = a.value;                 //将input中输入的value赋给td
		a = document.getElementById('b');    //或缺增加的input的id
        
        td = tr.cells[1]; //获取要修改的td的id
		var number = Number(a.value);
		if(!isNaN(number)){
			a.style.display = 'none';                //使input隐藏
			td.innerText = a.value;                 //将input中输入的value赋给td
		}else{
			alert("数量输入应为数字！！");
			return;
		}
		a = document.getElementById('c');    //或缺增加的input的id
        td = tr.cells[2]; //获取要修改的td的id
		number = Number(a.value);
		if(!isNaN(number)){
        	td.innerText = a.value;                 //将input中输入的value赋给td
			a.style.display = 'none';
		}else{
			a.value = 0;
			
			alert("价格输入应为数字！！");
			return;
		}
        bt = document.getElementById("btn"+countid); //获取button的id
		count[id] = 0;
        bt.innerHTML = "修改";
	}
	
	
	/*if (flag == 0) {
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
    }*/
}
			