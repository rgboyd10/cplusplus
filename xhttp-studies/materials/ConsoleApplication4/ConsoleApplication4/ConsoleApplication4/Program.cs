using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    public class GetSocket
    {
        public static void Main(string[] args)
        {
            var uri = new Uri(args[0]);
            var result = GetResource(uri);
            Console.WriteLine(result);
         }

        private static string GetResource(Uri uri)
        {
            var host = uri.Host;
            var resource = uri.PathAndQuery;
            var hostEntry = Dns.GetHostEntry();
            var socket = CreateSock(hostEntry);
            SendRequest(socket, host, resource);
            return GetResponse(socket);
        }

        private static Socket CreateSocket(IPHostEntry hostEntry)
        {
            const int httpPort = 80;

            //open socket
            var endPoint = new IPEndPoint(hostEntry.AddressList[0], httpPort);
            var socket = new Socket(endPoint.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            socket.Connect(endPoint);
            if (socket.Connected)
            {
                return socket;
            }
            return null;
        }

        private static void SendRequest(Socket socket, string host, string resource)
        {
            var requestMessage = String.Format("GET {0} HTTP/1.1\r\n" +
                                                "Host: {1}\r\n" +
                                                "\r\n",
                                                resource, host);

            var requestBytes = Encoding.ASCII.GetBytes(requestMessage);
            socket.Send(requestBytes);
        }

        private static string GetResponse(Socket socket)
        {
            int bytes = 0;
            byte[] buffer = new byte[256];
            var result = new StringBuilder();

            do
            {
                bytes = socket.Receive(buffer);
                result.Append(Encoding.ASCII.GetString(buffer, 0, bytes));
            }
            while (bytes > 0);

            return result.ToString();

        }


    }
}
