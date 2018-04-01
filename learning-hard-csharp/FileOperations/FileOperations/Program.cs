using System;
using System.Text;
using System.IO;

namespace FileOperations
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fileStream = null;
            string fileDir = AppDomain.CurrentDomain.BaseDirectory;
            string fileName = @"text.txt";
            string filePath = Path.Combine(fileDir, fileName);
            FileInfo fileInfo = new FileInfo(filePath);
            if(!fileInfo.Exists)
            {
                fileStream = File.Create(filePath);
                Console.WriteLine("new file: {0}.", filePath);
                fileStream.Close();
            }
            else
            {
                Console.WriteLine("{0} already exists.");
            }
            fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Write, FileShare.None, 4096, true);
            Console.WriteLine("start asychronous operation: {0}", fileStream.IsAsync);
            string message = DateTime.Now.ToString() + "\tHelloworld";
            byte[] buffer = Encoding.UTF8.GetBytes(message);
            IAsyncResult asyncResult = fileStream.BeginWrite(buffer, 0, buffer.Length, new AsyncCallback(EndWriteCallBack), fileStream);
            Console.WriteLine("start asynchronous write, please wait...");
            Console.Read();
        }

        static void EndWriteCallBack(IAsyncResult asyncResult)
        {
            Console.WriteLine("start asynchronous write...");
            FileStream fileStream = asyncResult.AsyncState as FileStream;
            if(fileStream != null)
            {
                fileStream.EndWrite(asyncResult);
                fileStream.Close();
            }
            Console.WriteLine("asynchonous write complete.");
        }
    }
}
