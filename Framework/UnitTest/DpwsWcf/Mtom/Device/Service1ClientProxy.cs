//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     .NET Micro Framework MFSvcUtil.Exe
//     Runtime Version:2.0.00001.0001
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


using System;
using System.Xml;
using Dpws.Client;
using Dpws.Client.Discovery;
using Dpws.Client.Eventing;
using Ws.Services;
using Ws.Services.Utilities;
using Ws.Services.Binding;
using Ws.Services.Soap;
using Ws.Services.Mtom;
using Ws.Services.WsaAddressing;
using Ws.Services.Xml;

namespace tempuri.org
{
    
    
    public class IDataAccessServiceClientProxy : DpwsClient
    {
        
        private IRequestChannel m_requestChannel = null;
        
        public IDataAccessServiceClientProxy(Binding binding, ProtocolVersion version) : 
                base(binding, version)
        {

            // Set client endpoint address
            m_requestChannel = m_localBinding.CreateClientChannel(new ClientBindingContext(m_version));
        }
        
        public virtual GetDataResponse GetData(GetData req)
        {

            // Create request header
            String action;
            action = "http://tempuri.org/IDataAccessService/GetData";
            WsWsaHeader header;
            header = new WsWsaHeader(action, null, EndpointAddress, m_version.AnonymousUri, null, null);
            WsMessage request = new WsMessage(header, req, WsPrefix.None);

            // Create request serializer
            GetDataDataContractSerializer reqDcs;
            reqDcs = new GetDataDataContractSerializer("GetData", "http://tempuri.org/");
            request.Serializer = reqDcs;
            request.Method = "GetData";


            // Indicate that this message will use Mtom encoding
            request.BodyParts = new WsMtomBodyParts();

            // Send service request
            m_requestChannel.Open();
            WsMessage response = m_requestChannel.Request(request);
            m_requestChannel.Close();

            // Process response
            GetDataResponseDataContractSerializer respDcs;
            respDcs = new GetDataResponseDataContractSerializer("GetDataResponse", "http://tempuri.org/");
            respDcs.BodyParts = response.BodyParts;
            GetDataResponse resp;
            resp = ((GetDataResponse)(respDcs.ReadObject(response.Reader)));
            response.Reader.Dispose();
            response.Reader = null;

            return resp;
        }
        
        public virtual SetDataResponse SetData(SetData req)
        {

            // Create request header
            String action;
            action = "http://tempuri.org/IDataAccessService/SetData";
            WsWsaHeader header;
            header = new WsWsaHeader(action, null, EndpointAddress, m_version.AnonymousUri, null, null);
            WsMessage request = new WsMessage(header, req, WsPrefix.None);

            // Create request serializer
            SetDataDataContractSerializer reqDcs;
            reqDcs = new SetDataDataContractSerializer("SetData", "http://tempuri.org/");
            request.Serializer = reqDcs;
            request.Method = "SetData";


            // Indicate that this message will use Mtom encoding
            request.BodyParts = new WsMtomBodyParts();

            // Send service request
            m_requestChannel.Open();
            WsMessage response = m_requestChannel.Request(request);
            m_requestChannel.Close();

            // Process response
            SetDataResponseDataContractSerializer respDcs;
            respDcs = new SetDataResponseDataContractSerializer("SetDataResponse", "http://tempuri.org/");
            respDcs.BodyParts = response.BodyParts;
            SetDataResponse resp;
            resp = ((SetDataResponse)(respDcs.ReadObject(response.Reader)));
            response.Reader.Dispose();
            response.Reader = null;

            return resp;
        }
        
        public virtual SetFileInfoResponse SetFileInfo(SetFileInfo req)
        {

            // Create request header
            String action;
            action = "http://tempuri.org/IDataAccessService/SetFileInfo";
            WsWsaHeader header;
            header = new WsWsaHeader(action, null, EndpointAddress, m_version.AnonymousUri, null, null);
            WsMessage request = new WsMessage(header, req, WsPrefix.None);

            // Create request serializer
            SetFileInfoDataContractSerializer reqDcs;
            reqDcs = new SetFileInfoDataContractSerializer("SetFileInfo", "http://tempuri.org/");
            request.Serializer = reqDcs;
            request.Method = "SetFileInfo";


            // Indicate that this message will use Mtom encoding
            request.BodyParts = new WsMtomBodyParts();

            // Send service request
            m_requestChannel.Open();
            WsMessage response = m_requestChannel.Request(request);
            m_requestChannel.Close();

            // Process response
            SetFileInfoResponseDataContractSerializer respDcs;
            respDcs = new SetFileInfoResponseDataContractSerializer("SetFileInfoResponse", "http://tempuri.org/");
            respDcs.BodyParts = response.BodyParts;
            SetFileInfoResponse resp;
            resp = ((SetFileInfoResponse)(respDcs.ReadObject(response.Reader)));
            response.Reader.Dispose();
            response.Reader = null;

            return resp;
        }
        
        public virtual GetNestedDataResponse GetNestedData(GetNestedData req)
        {

            // Create request header
            String action;
            action = "http://tempuri.org/IDataAccessService/GetNestedData";
            WsWsaHeader header;
            header = new WsWsaHeader(action, null, EndpointAddress, m_version.AnonymousUri, null, null);
            WsMessage request = new WsMessage(header, req, WsPrefix.None);

            // Create request serializer
            GetNestedDataDataContractSerializer reqDcs;
            reqDcs = new GetNestedDataDataContractSerializer("GetNestedData", "http://tempuri.org/");
            request.Serializer = reqDcs;
            request.Method = "GetNestedData";


            // Indicate that this message will use Mtom encoding
            request.BodyParts = new WsMtomBodyParts();

            // Send service request
            m_requestChannel.Open();
            WsMessage response = m_requestChannel.Request(request);
            m_requestChannel.Close();

            // Process response
            GetNestedDataResponseDataContractSerializer respDcs;
            respDcs = new GetNestedDataResponseDataContractSerializer("GetNestedDataResponse", "http://tempuri.org/");
            respDcs.BodyParts = response.BodyParts;
            GetNestedDataResponse resp;
            resp = ((GetNestedDataResponse)(respDcs.ReadObject(response.Reader)));
            response.Reader.Dispose();
            response.Reader = null;

            return resp;
        }
        
        public virtual SetNestedDataResponse SetNestedData(SetNestedData req)
        {

            // Create request header
            String action;
            action = "http://tempuri.org/IDataAccessService/SetNestedData";
            WsWsaHeader header;
            header = new WsWsaHeader(action, null, EndpointAddress, m_version.AnonymousUri, null, null);
            WsMessage request = new WsMessage(header, req, WsPrefix.None);

            // Create request serializer
            SetNestedDataDataContractSerializer reqDcs;
            reqDcs = new SetNestedDataDataContractSerializer("SetNestedData", "http://tempuri.org/");
            request.Serializer = reqDcs;
            request.Method = "SetNestedData";


            // Indicate that this message will use Mtom encoding
            request.BodyParts = new WsMtomBodyParts();

            // Send service request
            m_requestChannel.Open();
            WsMessage response = m_requestChannel.Request(request);
            m_requestChannel.Close();

            // Process response
            SetNestedDataResponseDataContractSerializer respDcs;
            respDcs = new SetNestedDataResponseDataContractSerializer("SetNestedDataResponse", "http://tempuri.org/");
            respDcs.BodyParts = response.BodyParts;
            SetNestedDataResponse resp;
            resp = ((SetNestedDataResponse)(respDcs.ReadObject(response.Reader)));
            response.Reader.Dispose();
            response.Reader = null;

            return resp;
        }
    }
}
