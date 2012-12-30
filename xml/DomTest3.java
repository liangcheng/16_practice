package xml.dom;
import java.io.File;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Attr;
import org.w3c.dom.Comment;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.NamedNodeMap;

/**
 * extract all element in the xml file using recursive
 * @author liang
 */
public class DomTest3 {
	public static void main(String[] args) throws Exception
	{
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
		DocumentBuilder db = dbf.newDocumentBuilder();
		Document doc = db.parse(new File("student.xml"));
		
		Element root = doc.getDocumentElement(); //obtain root element
		
		parseElement(root);
		
	}
	
	
	private static void parseElement(Element elem)
	{
		String tagName = elem.getNodeName();
		NodeList children = elem.getChildNodes();
		System.out.print("<"+tagName);
		NamedNodeMap map = elem.getAttributes(); // all attributes of element
		if (null !=map)// attributes exist
		{
			for(int i=0;i<map.getLength();i++)
			{
				Attr attr = (Attr)map.item(i);//obtain every attribute of this element
				String attrName = attr.getName();
				String attrValue = attr.getValue();
				System.out.print(" "+attrName+"=\""+attrValue+"\"");
			}
		}
		System.out.println(">");
		
		for(int i=0;i<children.getLength();i++)
		{
			Node node = children.item(i);
			short nodeType = node.getNodeType();
			
			if(nodeType == Node.ELEMENT_NODE)
			{
				parseElement((Element)node); //is element->recursive
			}
			else if(nodeType == Node.TEXT_NODE)
			{
				System.out.println(node.getNodeValue());
			}
		
		else if(nodeType ==Node.COMMENT_NODE)
		{	
			System.out.print("<!----");
			Comment comment = (Comment)node;
			String data=comment.getData(); //comment content
			System.out.print(data+"----->");
		}
			
			System.out.println("</"+tagName+">");
		}
		
	}

}
