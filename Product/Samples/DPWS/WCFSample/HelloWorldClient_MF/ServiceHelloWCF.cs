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
using System.Ext;
using System.Ext.Xml;
using Ws.ServiceModel;
using Ws.Services.Mtom;
using Ws.Services.Serialization;
using XmlElement = Ws.Services.Xml.WsXmlNode;
using XmlAttribute = Ws.Services.Xml.WsXmlAttribute;
using XmlConvert = Ws.Services.Serialization.WsXmlConvert;

namespace localhost.ServiceHelloWCF
{
    
    
    [DataContract(Namespace="http://localhost/ServiceHelloWCF")]
    public class HelloWCF
    {
        
        [DataMember(Order=0)]
        public string name;
    }
    
    public class HelloWCFDataContractSerializer : DataContractSerializer
    {
        
        public HelloWCFDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public HelloWCFDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            HelloWCF HelloWCFField = null;
            if (IsParentStartElement(reader, false, true))
            {
                HelloWCFField = new HelloWCF();
                reader.Read();
                if (IsChildStartElement(reader, "name", false, true))
                {
                    reader.Read();
                    HelloWCFField.name = reader.ReadString();
                    reader.ReadEndElement();
                }
                reader.ReadEndElement();
            }
            return HelloWCFField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            HelloWCF HelloWCFField = ((HelloWCF)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "name", false, true, HelloWCFField.name))
                {
                    writer.WriteString(HelloWCFField.name);
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/ServiceHelloWCF")]
    public class HelloWCFResponse
    {
        
        [DataMember(Order=0)]
        public string HelloWCFResult;
    }
    
    public class HelloWCFResponseDataContractSerializer : DataContractSerializer
    {
        
        public HelloWCFResponseDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public HelloWCFResponseDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            HelloWCFResponse HelloWCFResponseField = null;
            if (IsParentStartElement(reader, false, true))
            {
                HelloWCFResponseField = new HelloWCFResponse();
                reader.Read();
                if (IsChildStartElement(reader, "HelloWCFResult", false, true))
                {
                    reader.Read();
                    HelloWCFResponseField.HelloWCFResult = reader.ReadString();
                    reader.ReadEndElement();
                }
                reader.ReadEndElement();
            }
            return HelloWCFResponseField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            HelloWCFResponse HelloWCFResponseField = ((HelloWCFResponse)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "HelloWCFResult", false, true, HelloWCFResponseField.HelloWCFResult))
                {
                    writer.WriteString(HelloWCFResponseField.HelloWCFResult);
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [ServiceContract(Namespace="http://localhost/ServiceHelloWCF")]
    public interface IServiceHelloWCF
    {
        
        [OperationContract(Action="http://localhost/ServiceHelloWCF/IServiceHelloWCF/HelloWCF")]
        HelloWCFResponse HelloWCF(HelloWCF req);
    }
}
