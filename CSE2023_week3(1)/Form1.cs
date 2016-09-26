using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Windows.Forms;

namespace CSE2023_week3_1_
{
    public partial class Form1 : Form
    {
        String resultStr; //서버로부터 받아들인 결과 
        String message; //서버에 요청하는 메세지
        String URL = "http://210.94.194.100:20151/lab03.asp"; //POST 요청 보낸다.
        HttpWebRequest request; //서버의 응답을 통해 받아들인 결과
        StreamWriter sw;

        public void initHttpWebRequest() //HttpWebRequest객체 생성 및 초기화
        {
            request = (HttpWebRequest)WebRequest.Create(URL);
            //ULR로 요청을 보낸다.
            byte[] sendData = UTF8Encoding.UTF8.GetBytes(message);
            //메세지를 byte type으로 보낸다.
            request.ContentType = "application/x-www-form-urlencoded; charset=UTF-8";
            //요청을 보낼 때 MyVariableOne=ValueOne&MyVariableTwo=ValueTwo 과 같은 형태로 보낸다
            request.ContentLength = sendData.Length;
            request.Method = "POST";
        }
        public void initStreamWriter() //Streamwriter 객체 생성 및 초기화
        {   
            sw = new StreamWriter(request.GetRequestStream());
            sw.Write(message);
            sw.Close();
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            message = "cmd = color"; //color 요청
            initHttpWebRequest(); //HttpWebRequest호출
            initStreamWriter(); //StreamWriter호출
            HttpWebResponse httpWebResponse = (HttpWebResponse)request.GetResponse();
            //httpWebRequeset 객체를 GetResponse() 메서드를 사용하여 HttpWebResponse 객체로 반환한다.
            StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream(), Encoding.GetEncoding("UTF-8"));
            //서버로 부터 받아온 data를 StreamReader로 받는다
            resultStr = streamReader.ReadToEnd();
            //처음부터 끝까지 읽어서 String으로 저장한다.

            String[] str = resultStr.Split('|');
            // 서버로부터 받아온 결과에 '|' 를 기준으로 rgb 가 나누어짐으로 '|'로 끊는다.
            Color color = Color.FromArgb(int.Parse(str[0]), int.Parse(str[1]), int.Parse(str[2]));
            // Color 객체에 받아온 rgb 색상 코드를 입력한다.
            panel1.BackColor = color;
            // panel의 배경 색상을 바꾼다.

            streamReader.Close();
            httpWebResponse.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            message = "cmd = hello & name = Kim Kihyun";
            initHttpWebRequest();
            initStreamWriter();
            HttpWebResponse httpWebResponse = (HttpWebResponse)request.GetResponse();
            StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream(), Encoding.GetEncoding("UTF-8"));
            resultStr = streamReader.ReadToEnd();

            label1.Text = resultStr; //label의 text를 결과 text로 바꾼다.
            streamReader.Close();
            httpWebResponse.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            message = "cmd = echo & value = GoodJob!";
            initHttpWebRequest();
            initStreamWriter();
            HttpWebResponse httpWebResponse = (HttpWebResponse)request.GetResponse();
            StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream(), Encoding.GetEncoding("UTF-8"));
            resultStr = streamReader.ReadToEnd();

            MessageBox.Show(resultStr); //MessageBox에 결과를 띄운다.
            streamReader.Close();
            httpWebResponse.Close();

        }
    }
}
