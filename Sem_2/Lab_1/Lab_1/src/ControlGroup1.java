import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Group;


public class ControlGroup1
{
	Group group;
	Text text;
	Button button;
	Combo combo;

	ControlGroup1(Shell parentShell)
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
				if (!text.getText().equals(""))
				{
					boolean isSameFound = false;
					for (int currItem = 0; currItem < combo.getItems().length; currItem++)
					{
						if (text.getText().equals(combo.getItems()[currItem]))
						{
							isSameFound = true;
						}
					}
					if(!isSameFound)
					{
						combo.add(text.getText());
					}
					else
					{
						new ErrorWindow(parentShell).run();
					}
				}
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
		combo = new Combo(group, SWT.DROP_DOWN);
		combo.setLayoutData(new RowData(162, 0));
	}
}
