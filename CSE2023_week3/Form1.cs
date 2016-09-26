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

namespace CSE2023_week3
{
    public partial class Form1 : Form
    {
        String resultStr;
        String message;
        String URL = "http://210.94.194.100:20151/lab02.asp";
        HttpWebRequest request;

        public void initHttpWebRequest() //객체 생성 및 초기화
        {
            request = (HttpWebRequest)WebRequest.Create(URL);
            byte[] sendData = UTF8Encoding.UTF8.GetBytes(message);
            request.ContentType = "application/x-www-form-urlencoded; charset=UTF-8";
            request.ContentLength = sendData.Length;
            request.Method = "POST";
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void OnFormClosed(object sender, FormClosedEventArgs e)
        {
            Console.Write("OnFormClosed");
        }

        private void OnFormClosing(object sender, FormClosingEventArgs e)
        {
            Console.Write("OnFormClosing");
        }

        private void OnLoad(object sender, EventArgs e)
        {
            Console.Write("OnLoad");
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            message = "val = test";
            StreamWriter sw;
            initHttpWebRequest();
            sw = new StreamWriter(request.GetRequestStream());
            sw.Write(message);
            sw.Close();
            HttpWebResponse httpWebResponse = (HttpWebResponse)request.GetResponse();
            StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream(), Encoding.GetEncoding("UTF-8"));
            resultStr = streamReader.ReadToEnd();
            MessageBox.Show(resultStr);
            streamReader.Close();
            httpWebResponse.Close();
        }
    }
}

