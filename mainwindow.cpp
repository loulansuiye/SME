#include "mainwindow.h"
#include<QIcon>
#include<QList>
#include<QDebug>
#include<showwidget.h>
#include<QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle (tr("SME"));

    showWidget = new ShowWidget(this);
    showWidget->adjustSize ();

    setCentralWidget (showWidget);

    createActions ();
    createMenus ();
    createToolBars ();


    //createStatusBars();
    ;

}
void MainWindow::resizeEvent (QResizeEvent *event)
{
    ;//showWidget->resizeEvent (&event);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions ()
{
    //打开动作
    fileMenu_newFileAction = new QAction(QIcon(":/res/new.png"),tr("New"),this);
    fileMenu_newFileAction->setShortcut (tr("Ctrl+N"));
    fileMenu_newFileAction->setStatusTip (tr("Create A New File"));

    fileMenu_openFileAction = new QAction(QIcon(":/res/open.png"),tr("Open"),this);
    fileMenu_openFileAction->setShortcut (tr("Ctrl+O"));
    fileMenu_openFileAction->setStatusTip (tr("Open A File"));
connect(fileMenu_openFileAction,SIGNAL(triggered()),this,SLOT(file_open()));
    fileMenu_loadFileAction = new QAction(QIcon(":/res/load.png"),tr("Load"),this);
    fileMenu_loadFileAction->setStatusTip (tr("load a file"));

    fileMenu_browserFileAction= new QAction(QIcon(":/res/browser.png"),tr("Browser Files..."),this);
    fileMenu_browserFileAction->setStatusTip (tr("browser"));

    fileMenu_newClipAction= new QAction(QIcon(":/res/clicp.png"),tr("New Clip..."),this);
    fileMenu_newClipAction->setStatusTip (tr("create a new clip"));

    fileMenu_recentFileMenu= new QMenu(tr("Recent Files"),this);
    fileMenu_recentFileMenu->setStatusTip (tr("Recent Files..."));


    fileMenu_closeFileAction= new QAction(QIcon(":/res/close.png"),tr("Close"),this);
    fileMenu_closeFileAction->setShortcut (tr("Ctrl+W"));
    fileMenu_closeFileAction->setStatusTip (tr("Close current file"));

    fileMenu_closeAllFileAction= new QAction(QIcon(":/res/closeall.png"),tr("Close All"),this);
    fileMenu_closeAllFileAction->setShortcut (tr("Ctrl+Shift+W"));
    fileMenu_closeAllFileAction->setStatusTip (tr("Close all files"));

    fileMenu_reloadFileAction= new QAction(tr("Reload File"),this);
    fileMenu_reloadFileAction->setShortcut (tr("Ctrl+Shift+O"));
    fileMenu_reloadFileAction->setStatusTip (tr("reload a file"));

    fileMenu_restoreFileAction= new QAction(tr("Restore File"),this);
    fileMenu_restoreFileAction->setStatusTip (tr("Restore files"));

    fileMenu_renameAction= new QAction(tr("Rename..."),this);

    fileMenu_renameAction->setStatusTip (tr("Rename"));

    fileMenu_deleteFileAction= new QAction(tr("Delete File..."),this);
    fileMenu_deleteFileAction->setStatusTip (tr("Delete File..."));

    fileMenu_reloadModifiedFileAction= new QAction(tr("Reload Modified Files"),this);
    fileMenu_reloadModifiedFileAction->setStatusTip (tr("Reload Modified Files"));

    fileMenu_saveAction= new QAction(QIcon(tr(":/res/save.png")),tr("Save"),this);
    fileMenu_saveAction->setShortcut (tr("Ctrl+S"));
    fileMenu_saveAction->setStatusTip (tr("Save"));

    fileMenu_saveAsAction= new QAction(tr("Save As..."),this);
    fileMenu_saveAsAction->setShortcut (tr("Ctrl+Shift+S"));
    fileMenu_saveAsAction->setStatusTip (tr("Save As..."));

    fileMenu_saveAllAction= new QAction(QIcon(tr(":/res/save_all.png")),tr("Save All"),this);
    fileMenu_saveAllAction->setShortcut (tr("Ctrl+A"));
    fileMenu_saveAllAction->setStatusTip (tr("Save All"));

    fileMenu_saveACopyAction= new QAction(tr("Save A Copy..."),this);
    fileMenu_saveACopyAction->setStatusTip (tr("Save A Copy..."));

    fileMenu_saveSelectedAction= new QAction(tr("Save Selected"),this);
    fileMenu_saveSelectedAction->setStatusTip (tr("save all selected"));

    fileMenu_loadWorkspaceAction= new QAction(tr("Load workspace"),this);
    fileMenu_loadWorkspaceAction->setStatusTip (tr("load workspace"));

    fileMenu_saveWorkspaceAction= new QAction(tr("Save workspace"),this);
    fileMenu_saveWorkspaceAction->setStatusTip (tr("Save workspace"));

    fileMenu_printTextAction= new QAction(QIcon(tr(":/res/print.png")),tr("print"),this);
    fileMenu_printTextAction->setStatusTip (tr("Print"));

    fileMenu_printPreviewAction= new QAction(tr("Print preview..."),this);
    fileMenu_printPreviewAction->setStatusTip (tr("Print preview"));

    fileMenu_exitAction= new QAction(tr("Exit"),this);
    fileMenu_exitAction->setShortcut (tr("Alt+F4"));
    fileMenu_exitAction->setStatusTip (tr("Exit"));

    editMenu_undo_action = new QAction(tr("Undo"),this);  //编辑菜单项
    editMenu_undo_action->setShortcut (tr("Ctrl+Z"));
    editMenu_redo_action = new QAction(tr("Redo"),this);
    editMenu_redo_action->setShortcut (tr("Ctrl+Y"));
    editMenu_undo_all_action = new QAction(tr("Undo All"),this);
    editMenu_redo_all_action = new QAction(tr("Redo All"),this);
edit_do_list<<editMenu_undo_action<<editMenu_redo_action<<editMenu_undo_all_action<<editMenu_redo_all_action;
    editMenu_copy_action = new QAction(tr("Copy"),this);
    editMenu_copy_action->setShortcut (tr("Ctrl+C"));
    editMenu_cut_action = new QAction(tr("Cut"),this);
    editMenu_cut_action->setShortcut (tr("Ctrl+X"));
    editMenu_paste_action = new QAction(tr("Paste"),this);
    editMenu_paste_action->setShortcut (tr("Ctrl+V"));
    editMenu_duplicate_action = new QAction(tr("Cuplicate"),this);
    basic_edit_list<<editMenu_copy_action<<editMenu_cut_action<<editMenu_paste_action<<editMenu_duplicate_action;

    editMenu_cut_to_clip_action = new QAction(tr("Cut to Clip..."),this);
    editMenu_cut_to_clip_action->setShortcut (tr("Ctrl+Shift+X"));
    editMenu_copy_to_clip_action = new QAction(tr("Copy to Clip..."),this);
    editMenu_copy_to_clip_action->setShortcut (tr("Ctrl+Del"));
    editMenu_paste_from_clip_action = new QAction(tr("Paste From Clip.."),this);
    editMenu_paste_from_clip_action->setShortcut (tr("Ctrl+Ins"));
    edit_clip_list<<editMenu_cut_to_clip_action<<editMenu_copy_to_clip_action<<editMenu_paste_from_clip_action;
    editMenu_insert_file_action = new QAction(tr("Insert File..."),this);
    editMenu_renumber_action = new QAction(tr("Renumber..."),this);
    editMenu_renumber_action->setShortcut (tr("Ctrl+R"));
    editMenu_smart_rename_action = new QAction(tr("Smart Rename"),this);
editMenu_smart_rename_action->setShortcut (tr("Ctrl+'"));
    editMenu_select_all_action = new QAction(tr("Select All"),this);
    editMenu_select_function_or_symbol_action = new QAction(tr("Select Function Or Symbol"),this);
    editMenu_select_block_action = new QAction(tr("Select Block"),this);
    editMenu_specical_edit_action = new QMenu(tr("Specical Edit"),this);
    select_list<<editMenu_select_all_action<<editMenu_select_function_or_symbol_action<<editMenu_select_block_action;
    editMenu_specical_edit_action_Uppercase = new QAction(tr("Upper case"),this);
    editMenu_specical_edit_action_Lowercase = new QAction(tr("Lower case"),this);
    editMenu_specical_edit_action_Togglecase = new QAction(tr("Toggle case"),this);
editMenu_special_case_list<<editMenu_specical_edit_action_Uppercase<<editMenu_specical_edit_action_Lowercase<<editMenu_specical_edit_action_Togglecase;
    editMenu_specical_edit_action_Spaces_To_Tab = new QAction(tr("Spaces to tab"),this);
    editMenu_specical_edit_action_Tabs_To_Spaces = new QAction(tr("Tab to spaces"),this);
editMenu_special_space_tab_list<<editMenu_specical_edit_action_Spaces_To_Tab<<editMenu_specical_edit_action_Tabs_To_Spaces;
    editMenu_specical_edit_action_Insert_ASCII = new QAction(tr("Insert ascii"),this);
    editMenu_specical_edit_action_Reform_Paragraph = new QAction(tr("Reform paragraph"),this);
    editMenu_specical_edit_action_Calculate = new QAction(tr("calculate"),this);
editMenu_special_charsets_list<<editMenu_specical_edit_action_Insert_ASCII<<editMenu_specical_edit_action_Reform_Paragraph<<editMenu_specical_edit_action_Calculate;

editMenu_specical_edit_action_Indent_Right = new QAction(tr("Indent right"),this);
    editMenu_specical_edit_action_Indent_Left = new QAction(tr("Indent Left"),this);
    editMenu_special_indent_list<<editMenu_specical_edit_action_Indent_Right<<editMenu_specical_edit_action_Indent_Left;


    editMenu_start_recording_action = new QAction(tr("Start Recording"),this);
    editMenu_stop_recording_action = new QAction(tr("Stop Recording"),this);
    editMenu_play_recording_action = new QAction(tr("Play Recording"),this);
    recording_list<<editMenu_start_recording_action<<editMenu_stop_recording_action<<editMenu_play_recording_action;



    searchMenu_search_action = new QAction(tr("Search..."),this);   //search菜单项
    searchMenu_search_action->setShortcut (tr("Ctrl+F"));
    searchMenu_search_files_action= new QAction(tr("Search Files..."),this);
    searchMenu_search_files_action->setShortcut (tr("Ctrl+Shift+F"));
    searchMenu_search_project_action= new QAction(tr("Search Project..."),this);
    searchMenu_lookup_reference_action= new QAction(tr("Lookup References..."),this);
    searchMenu_lookup_reference_action->setShortcut (tr("Ctrl+/"));
    searchMenu_search_forward_action= new QAction(tr("Search Forward..."),this);
    searchMenu_search_backwardaction= new QAction(tr("Search Backward..."),this);

    searchMenu_one_list<<searchMenu_search_action<<searchMenu_search_files_action<<searchMenu_search_project_action<<searchMenu_lookup_reference_action<<searchMenu_search_forward_action<<searchMenu_search_backwardaction;
    searchMenu_replace_action= new QAction(tr("Replace..."),this);
    searchMenu_replace_files_action= new QAction(tr("Replace Files..."),this);
    searchMenu_two_list<<searchMenu_replace_action<<searchMenu_replace_files_action;

    searchMenu_bookmar_action= new QAction(tr("Bookmark..."),this);
    searchMenu_select_history_action= new QAction(tr("Selection History..."),this);
    searchMenu_go_to_line_action= new QAction(tr("Go To Line..."),this);
    searchMenu_three_list<<searchMenu_bookmar_action<<searchMenu_select_history_action<<searchMenu_go_to_line_action;

    searchMenu_go_back_action= new QAction(tr("Go Back..."),this);
    searchMenu_go_forward_action= new QAction(tr("Go Forward..."),this);
    searchMenu_four_list<<searchMenu_go_back_action<<searchMenu_go_forward_action;

    searchMenu_jump_to_link_action= new QAction(tr("Jump To Link..."),this);
    searchMenu_go_to_previous_link_action= new QAction(tr("Go To Previous Link..."),this);
    searchMenu_go_to_next_link_action= new QAction(tr("Go To Next Link..."),this);
    searchMenu_parse_source_links_action= new QAction(tr("Parse Source Links"),this);
    searchMenu_five_list<<searchMenu_jump_to_link_action<<searchMenu_go_to_previous_link_action<<searchMenu_go_to_next_link_action<<searchMenu_parse_source_links_action;

    searchMenu_browser_project_symbols_aciton= new QAction(tr("Browser Project Symbols"),this);
    searchMenu_browser_local_file_symbols_action= new QAction(tr("Browser Local File"),this);
    searchMenu_jump_to_definition_action= new QAction(tr("Jump To Definition"),this);
    searchMenu_six_list<<searchMenu_browser_project_symbols_aciton<<searchMenu_browser_local_file_symbols_action<<searchMenu_jump_to_definition_action;

    projectMenu_new_project_action= new QAction(tr("New Project"),this);  //project菜单选项
    projectMenu_open_project_action= new QAction(tr("Open Project"),this);
    projectMenu_close_project_action= new QAction(tr("Close Project"),this);
    projectMenu_remove_project_action= new QAction(tr("Remove Project"),this);
    projectMenu_one_list<<projectMenu_new_project_action<<projectMenu_open_project_action<<projectMenu_close_project_action<<projectMenu_remove_project_action;
    projectMenu_add_and_remove_project_files_action= new QAction(tr("Add And Remove Project"),this);
    projectMenu_synchronize_files_action= new QAction(tr("Synchronize Files"),this);
    projectMenu_two_list<<projectMenu_add_and_remove_project_files_action<<projectMenu_synchronize_files_action;
    projectMenu_project_report_action= new QAction(tr("Project Report"),this);
    projectMenu_rebuild_project_action= new QAction(tr("Rebuild Project"),this);
    projectMenu_three_list<<projectMenu_project_report_action<<projectMenu_rebuild_project_action;
    projectMenu_project_settings_action= new QAction(tr("Project Settings"),this);


    optionMenu_preferences_action= new QAction(tr("Preferences..."),this);
    optionMenu_one_list<<optionMenu_preferences_action;
    connect(optionMenu_preferences_action,SIGNAL(triggered()),this,SLOT(preferenceSetting()));
   // connect(helpMenu_bug_feedback_action,SIGNAL(triggered()),this,SLOT(bug_feedback_slot()));
    optionMenu_document_options_action= new QAction(tr("Document Options..."),this);
    optionMenu_style_properties_action= new QAction(tr("Style Properties..."),this);
    optionMenu_two_list<<optionMenu_document_options_action<<optionMenu_style_properties_action;

    optionMenu_key_assignments_action= new QAction(tr("Key Assignments..."),this);
    optionMenu_menu_assignments_action= new QAction(tr("Menu Assignments..."),this);
    optionMenu_custom_commands_action= new QAction(tr("Custom Commands..."),this);
optionMenu_three_list<<optionMenu_key_assignments_action<<optionMenu_menu_assignments_action<<optionMenu_custom_commands_action;

    optionMenu_load_configuration_action= new QAction(tr("Load Configuration..."),this);
    optionMenu_save_configuration_action= new QAction(tr("Save Configuration..."),this);
optionMenu_four_list<<optionMenu_load_configuration_action<<optionMenu_save_configuration_action;


    viewMenu_toolbars= new QMenu(tr("Toolbars"),this);   //view 菜单项
    viewMenu_toolbars_action_main_toolbar= new QAction(tr("Main Toolbar"),this);
    viewMenu_toolbars_action_standard= new QAction(tr("Standard"),this);
    viewMenu_toolbars_action_edit= new QAction(tr("Edit"),this);
    viewMenu_toolbars_action_search= new QAction(tr("Search"),this);
    viewMenu_toolbars_action_navigation= new QAction(tr("Navigation"),this);
    viewMenu_toolbars_action_symbols= new QAction(tr("Symbols"),this);
    viewMenu_toolbars_action_arrangement= new QAction(tr("Arrangement"),this);
    viewMenu_toolbars_action_view= new QAction(tr("View"),this);
    viewMenu_toolbars_action_help= new QAction(tr("Help"),this);
    viewMenu_toolbars_action_source_control= new QAction(tr("Soure Control"),this);
    viewMenu_toolbars_action_build= new QAction(tr("Build"),this);
    viewMenu_one_list<<viewMenu_toolbars_action_main_toolbar<<viewMenu_toolbars_action_standard<<viewMenu_toolbars_action_edit<<viewMenu_toolbars_action_search<<viewMenu_toolbars_action_navigation<<viewMenu_toolbars_action_symbols<<viewMenu_toolbars_action_arrangement<<viewMenu_toolbars_action_view<<viewMenu_toolbars_action_help<<viewMenu_toolbars_action_source_control<<viewMenu_toolbars_action_build;
    viewMenu_toolbars->addActions(viewMenu_one_list);

    viewMenu_status_bar_action= new QAction(tr("Status Bar"),this);
    viewMenu_horizontal_scroll_bar_action= new QAction(tr("Horizontal Scroll Bar"),this);
    viewMenu_line_number_action= new QAction(tr("Line Number"),this);
    viewMenu_two_list<<viewMenu_status_bar_action<<viewMenu_horizontal_scroll_bar_action<<viewMenu_line_number_action;

    viewMenu_project_window_action= new QAction(tr("Project Window"),this);
    viewMenu_clip_window_action= new QAction(tr("Clip Window"),this);
    viewMenu_symbol_window_action= new QAction(tr("Symbol Window"),this);
    viewMenu_symbol_window_action->setShortcut (tr("Alt+F8"));
    viewMenu_context_window_action= new QAction(tr("Context Window"),this);
    viewMenu_relation_window_action= new QAction(tr("Relation Window"),this);
    viewMenu_three_list<<viewMenu_project_window_action<<viewMenu_clip_window_action<<viewMenu_symbol_window_action<<viewMenu_context_window_action<<viewMenu_relation_window_action;
    viewMenu_show_clipboard_action= new QAction(tr("Show Clipboard"),this);
    viewMenu_draft_view_action= new QAction(tr("Draft View"),this);
    viewMenu_four_list<<viewMenu_show_clipboard_action<<viewMenu_draft_view_action;

    windowMenu_new_window_action= new QAction(tr("New Window"),this); //window菜单项
    windowMenu_new_window_action->setShortcut (tr("Alt+F5"));
    windowMenu_close_window_action= new QAction(tr("Close Window"),this);
    windowMenu_close_window_action->setShortcut (tr("Alt+F6"));
    windowMenu_one_list<<windowMenu_new_window_action<<windowMenu_close_window_action;

    windowMenu_Cascade_window_action= new QAction(tr("Cascade Window"),this);
    windowMenu_title_horizontal_action= new QAction(tr("Title Horizontal"),this);
    windowMenu_title_vertical_action= new QAction(tr("Title Vertical"),this);
    windowMenu_title_one_widnow_action= new QAction(tr("Title One Window"),this);
    windowMenu_title_two_window_action= new QAction(tr("Title Two Window"),this);
    windowMenu_title_two_window_action->setShortcut (tr("F6"));
    windowMenu_two_list<<windowMenu_Cascade_window_action<<windowMenu_title_horizontal_action<<windowMenu_title_vertical_action<<windowMenu_title_one_widnow_action<<windowMenu_title_two_window_action;

    windowMenu_link_window_action= new QAction(tr("Link Window..."),this);
    windowMenu_link_all_windows_action= new QAction(tr("Link All Windows..."),this);
    windowMenu_windows_list_action= new QAction(tr("Window List..."),this);

    windowMenu_three_list<<windowMenu_link_window_action<<windowMenu_link_all_windows_action<<windowMenu_windows_list_action;

    helpMenu_help_action= new QAction(tr("Help..."),this);
    helpMenu_help_mode_action= new QAction(tr("Help Mode..."),this);
    helpMenu_html_help_aciton= new QAction(tr("Html Help..."),this);
    helpMenu_sdk_help_action= new QAction(tr("Sdk Help..."),this);
    helpMenu_create_key_list_action= new QAction(tr("Create Key List..."),this);
    helpMenu_create_command_list= new QAction(tr("Create Command List..."),this);
    helpMenu_one_list<<helpMenu_help_action<<helpMenu_help_mode_action<<helpMenu_html_help_aciton<<helpMenu_sdk_help_action<<helpMenu_create_key_list_action<<helpMenu_create_command_list;

    helpMenu_ordering_information_action= new QAction(tr("Ordering Information"),this);
    helpMenu_serical_number_action= new QAction(tr("Serial Number ..."),this);
    helpMenu_source_dynameics_on_the_web_action= new QAction(tr("Source Dynamics on the Web"),this);
    helpMenu_about_source_insight_custom_action= new QAction(tr("About Source Insight Custom..."),this);
    helpMenu_bug_feedback_action = new QAction(tr("Bug FeekBack"),this);
    connect(helpMenu_bug_feedback_action,SIGNAL(triggered()),this,SLOT(bug_feedback_slot()));
    helpMenu_two_list<<helpMenu_ordering_information_action<<helpMenu_serical_number_action<<helpMenu_source_dynameics_on_the_web_action<<helpMenu_about_source_insight_custom_action<<helpMenu_bug_feedback_action;

}

void MainWindow::createMenus ()
{
    fileMenu = menuBar ()->addMenu (tr("File"));
    fileMenu->adjustSize();
    fileMenu->addAction(fileMenu_openFileAction);
    fileMenu->addAction(fileMenu_newFileAction);
    fileMenu->addAction(fileMenu_loadFileAction);
    fileMenu->addAction(fileMenu_browserFileAction);
    fileMenu->addAction(fileMenu_newClipAction);
    fileMenu->addMenu(fileMenu_recentFileMenu);
    fileMenu->addSeparator ();
    fileMenu->addAction(fileMenu_closeFileAction);
    fileMenu->addAction(fileMenu_closeAllFileAction);
    fileMenu->addAction(fileMenu_reloadFileAction);
    fileMenu->addAction(fileMenu_restoreFileAction);
    fileMenu->addAction(fileMenu_renameAction);
    fileMenu->addAction(fileMenu_deleteFileAction);
    fileMenu->addAction(fileMenu_reloadModifiedFileAction);
    fileMenu->addSeparator ();
    fileMenu->addAction(fileMenu_saveAction);
    fileMenu->addAction(fileMenu_saveAsAction);
    fileMenu->addAction(fileMenu_saveAllAction);
    fileMenu->addAction(fileMenu_saveACopyAction);
    fileMenu->addAction(fileMenu_saveSelectedAction);
    fileMenu->addSeparator ();
    fileMenu->addAction(fileMenu_loadWorkspaceAction);
    fileMenu->addAction(fileMenu_saveWorkspaceAction);
    fileMenu->addSeparator ();
    fileMenu->addAction(fileMenu_printTextAction);
    fileMenu->addAction(fileMenu_printPreviewAction);
    fileMenu->addSeparator ();
    fileMenu->addAction(fileMenu_exitAction);
    connect(fileMenu_exitAction,SIGNAL(triggered()),this,SLOT(file_exit()));

    editMenu = menuBar ()->addMenu (tr("Edit"));
    editMenu->addActions(edit_do_list);
    editMenu->addSeparator ();
    editMenu->addActions(basic_edit_list);
    editMenu->addSeparator ();
    editMenu->addActions(edit_clip_list);
    editMenu->addSeparator ();
    editMenu->addAction(editMenu_insert_file_action);
    editMenu->addAction(editMenu_renumber_action);
    editMenu->addAction(editMenu_smart_rename_action);
    editMenu->addSeparator ();
    editMenu->addActions (select_list);
    editMenu->addMenu (editMenu_specical_edit_action);
    editMenu_specical_edit_action->addActions(editMenu_special_case_list);
    editMenu_specical_edit_action->addSeparator ();
    editMenu_specical_edit_action->addActions(editMenu_special_space_tab_list);
    editMenu_specical_edit_action->addSeparator ();
    editMenu_specical_edit_action->addActions(editMenu_special_charsets_list);
    editMenu_specical_edit_action->addSeparator ();
    editMenu_specical_edit_action->addActions(editMenu_special_indent_list);

    //editMenu->addActions(editMenu_special_edit_list);
    editMenu->addSeparator ();
    editMenu->addActions(recording_list);


    searchMenu= menuBar ()->addMenu(tr("Search"));
    searchMenu->addActions (searchMenu_one_list);
    searchMenu->addSeparator ();
    searchMenu->addActions (searchMenu_two_list);
    searchMenu->addSeparator ();
    searchMenu->addActions (searchMenu_three_list);
    searchMenu->addSeparator ();
    searchMenu->addActions (searchMenu_four_list);
    searchMenu->addSeparator ();
    searchMenu->addActions (searchMenu_five_list);
    searchMenu->addSeparator ();
    searchMenu->addActions (searchMenu_six_list);

    projectMenu= menuBar ()->addMenu(tr("Project"));
    projectMenu->addActions (projectMenu_one_list);
    projectMenu->addSeparator ();
    projectMenu->addActions (projectMenu_two_list);
    projectMenu->addSeparator ();
    projectMenu->addActions (projectMenu_three_list);
    projectMenu->addSeparator ();
    projectMenu->addActions (projectMenu_four_list);
    //projectMenu->addSeparator ();

    optionMenu= menuBar ()->addMenu(tr("Option"));
    optionMenu->addActions (optionMenu_one_list);
    optionMenu->addSeparator ();
    optionMenu->addActions (optionMenu_two_list);
    optionMenu->addSeparator ();
    optionMenu->addActions (optionMenu_three_list);
    optionMenu->addSeparator ();
    optionMenu->addActions (optionMenu_four_list);
    viewMenu = menuBar ()->addMenu (tr("View"));
    viewMenu_toolbars->addActions (viewMenu_one_list);
    viewMenu->addMenu (viewMenu_toolbars);
  //  viewMenu->addActions (viewMenu_one_list);
   // viewMenu->addSeparator ();
    viewMenu->addActions (viewMenu_two_list);
    viewMenu->addSeparator ();
    viewMenu->addActions (viewMenu_three_list);
    viewMenu->addSeparator ();
    viewMenu->addActions (viewMenu_four_list);


    windowMenu = menuBar()->addMenu (tr("Window"));
    windowMenu->addActions (windowMenu_one_list);
    windowMenu->addSeparator ();
    windowMenu->addActions (windowMenu_two_list);
    windowMenu->addSeparator ();
    windowMenu->addActions (windowMenu_three_list);
    //windowMenu->addSeparator ();
   // windowMenu->addActions (windowMenu_four_list);
    aboutMenu = menuBar()->addMenu (tr("Help"));
    aboutMenu->addActions (helpMenu_one_list);
    aboutMenu->addSeparator ();
    aboutMenu->addActions (helpMenu_two_list);



}

void MainWindow::createToolBars ()
{
   QList<QAction *> action_list ;//= new QList(this);
   action_list<<fileMenu_openFileAction<<fileMenu_newFileAction<<fileMenu_saveAction<<fileMenu_saveAllAction<<fileMenu_printTextAction;
   file_toolbar = addToolBar ("File");
   file_toolbar->addActions (action_list);
   file_toolbar->addSeparator ();
}
void MainWindow::bug_feedback_slot ()
{
  qDebug()<<"bug feed back via my email";
  bugfeedback = new BugFeedback();
  //setCentralWidget(bugfeedback);
  bugfeedback->exec ();
// ;

}
void MainWindow::file_exit ()
{
    close();
}
void MainWindow::preferenceSetting()
{
    preferenceDlg = new PreferencesDlg();
    preferenceDlg->exec ();
}

void MainWindow::createStatusBars()
{
   statusbar = new QStatusBar(this);
}

void MainWindow::file_open()
{
    QString  directory= QFileDialog::getExistingDirectory(this,
                               tr("Find Files"), QDir::currentPath());
    //QString strPath = QDir::currentPath ();
    //qDebug("current directory is %s")<<directory;
    //fileDialog->exec();
    //QString fileName  = QFileDialog.getOpenFileName ()
}
