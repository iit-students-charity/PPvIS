package lab_2.gui;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;

import lab_2.controls.SearchDialogControl;

public class SearchDialog{
	Display display;
	Shell shell;
	final int width = 340;
	final int height = 420;
	Text text;
	GridData textData;
	
	public SearchDialog(Shell parent) {
	    display = parent.getDisplay();
	    shell = new Shell();
		initUI();
		new SearchDialogControl(display, shell).run();
	}
	
	private void initUI() {
		shell.setText("Поиск");
		shell.setSize(width, height);
		GridLayout shellLayout = new GridLayout();
		shellLayout.numColumns = 1;
		shell.setLayout(shellLayout);
		
		Group radioGroup = new Group(shell, SWT.NONE);
		radioGroup.setLayout(new RowLayout(SWT.HORIZONTAL));
		
		Button nameSport = new Button(radioGroup, SWT.RADIO);
		nameSport.setText(" По ФИО или виду спорта");
		nameSport.addSelectionListener(new SelectionAdapter() {
            @Override
            public void widgetSelected(SelectionEvent event) {
                Button source = (Button)event.getSource();
                if(source.getSelection())  {
                	showTextInput();
                }
            }
		});
		Button titles = new Button(radioGroup, SWT.RADIO);
		titles.setText("По количеству титулов");
		titles.addSelectionListener(new SelectionAdapter() {
            @Override
            public void widgetSelected(SelectionEvent e) {
                Button source = (Button)e.getSource();
                if(source.getSelection())  {
                	showTextInput();
                }
            }
		});
		Button nameRank = new Button(radioGroup, SWT.RADIO);
		nameRank.setText("По ФИО или разряду");
		nameRank.addSelectionListener(new SelectionAdapter() {
            @Override
            public void widgetSelected(SelectionEvent e) {
                Button source = (Button)e.getSource();
                if(source.getSelection())  {
                	showRangeInput();
                }
            }
		});
		
		text = new Text(shell, SWT.LEFT);
		textData = new GridData();
		textData.exclude = false;
		textData.horizontalAlignment = SWT.FILL;
        text.setLayoutData(textData);
		        
		shell.pack();
	}
	
	private void showRangeInput() {
		textData.exclude = true;
        text.setVisible(!textData.exclude);
        shell.layout(false);
        shell.pack();
	}
	
	private void showTextInput() {
        textData.exclude = false;
        text.setVisible(!textData.exclude);
        shell.layout(false);
        shell.pack();
	}
}
