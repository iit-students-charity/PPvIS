import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Group;

public class ControlGroup2
{
	Group group;
	Text text;
	Button button;
	Button button2;
	
	ControlGroup2(Shell parentShell) 
	{			
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
				if (text.getText() != "")
				{
					button2.setText(text.getText());
				}
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
		
		button2 = new Button(group, SWT.PUSH);
		button2.setText("Click Me 2");
		button2.setLayoutData(new RowData(190, 50));
		button2.addSelectionListener(new SelectionListener() 
		{
			@Override
			public void widgetSelected(SelectionEvent event) 
			{
					String temp = button.getText();
					button.setText(button2.getText());
					button2.setText(temp);
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
	}
}
