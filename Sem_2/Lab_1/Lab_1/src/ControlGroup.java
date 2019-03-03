import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;


//Base class of each control group
public class ControlGroup
{
	Shell parentShell;
	Group group;
	Text text;
	String inputtedText;
	Button button;
	
	ControlGroup(Shell otherShell)
	{
		parentShell = otherShell;
		
		group = new Group(parentShell, SWT.NONE);
		group.setLayout(new RowLayout(SWT.VERTICAL));
		
		text = new Text(group, SWT.NULL);
		text.setLayoutData(new RowData(182, 50));
		
		button = new Button(group, SWT.PUSH);
		button.setText("Click Me");
		button.setLayoutData(new RowData(190, 50));
		button.addSelectionListener(new SelectionListener()
		{
			@Override
			public void widgetSelected(SelectionEvent event) 
			{
				inputtedText = text.getText();
				buttonAction();
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
	}
	
	public void buttonAction(){}
}
