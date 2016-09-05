#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QObject>
#include <QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QToolBar>
#include<QFontComboBox>
#include<QSpinBox>
#include<QDockWidget>
#include<QWidget>
#include<QStatusBar>
#include"bugfeedback.h"
#include"showwidget.h"
#include<preferencesdlg.h>
#include<QFileDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createActions(); //创建动作
    void createMenus(); //创建菜单
    void createToolBars(); //创建工具栏
    void createStatusBars();  //创建状态栏
    void openFile(QString filename); //打开文件
    void resizeEvent (QResizeEvent *event);

private:
    ShowWidget *showWidget;
    QMenu *fileMenu;  //各个菜单栏
    QMenu *editMenu;
    QMenu *searchMenu;
    QMenu *projectMenu;
    QMenu *optionMenu;
    QMenu *viewMenu;
    QMenu *windowMenu;
    QMenu *aboutMenu;

    QAction *fileMenu_newFileAction;//文件菜单项
    QAction *fileMenu_openFileAction;
    QAction *fileMenu_loadFileAction;
    QAction *fileMenu_browserFileAction;
    QAction *fileMenu_newClipAction;
    QMenu *fileMenu_recentFileMenu;

    QAction *fileMenu_closeFileAction;
    QAction *fileMenu_closeAllFileAction;
    QAction *fileMenu_reloadFileAction;
    QAction *fileMenu_restoreFileAction;
    QAction *fileMenu_renameAction;
    QAction *fileMenu_deleteFileAction;
    QAction *fileMenu_reloadModifiedFileAction;


    QAction *fileMenu_saveAction;
    QAction *fileMenu_saveAsAction;
    QAction *fileMenu_saveAllAction;
    QAction *fileMenu_saveACopyAction;
    QAction *fileMenu_saveSelectedAction;


    QAction *fileMenu_loadWorkspaceAction;
    QAction *fileMenu_saveWorkspaceAction;

    QAction *fileMenu_printTextAction;
    QAction *fileMenu_printPreviewAction;

    QAction *fileMenu_exitAction;




    QAction *editMenu_undo_action;  //编辑菜单项
    QAction *editMenu_redo_action;
    QAction *editMenu_undo_all_action;
    QAction *editMenu_redo_all_action;

    QAction *editMenu_copy_action;
    QAction *editMenu_cut_action;
    QAction *editMenu_paste_action;
    QAction *editMenu_duplicate_action;

    QAction *editMenu_cut_to_clip_action;
    QAction *editMenu_copy_to_clip_action;
    QAction *editMenu_paste_from_clip_action;


    QAction *editMenu_insert_file_action;
    QAction *editMenu_renumber_action;
    QAction *editMenu_smart_rename_action;

    QAction *editMenu_select_all_action;
    QAction *editMenu_select_function_or_symbol_action;
    QAction *editMenu_select_block_action;
    QMenu *editMenu_specical_edit_action;

    QAction *editMenu_specical_edit_action_Uppercase;
    QAction *editMenu_specical_edit_action_Lowercase;
    QAction *editMenu_specical_edit_action_Togglecase;

    QAction *editMenu_specical_edit_action_Spaces_To_Tab;
    QAction *editMenu_specical_edit_action_Tabs_To_Spaces;

    QAction *editMenu_specical_edit_action_Insert_ASCII;
    QAction *editMenu_specical_edit_action_Reform_Paragraph;
    QAction *editMenu_specical_edit_action_Calculate;

    QAction *editMenu_specical_edit_action_Indent_Right;
    QAction *editMenu_specical_edit_action_Indent_Left;

    QAction *editMenu_start_recording_action;
    QAction *editMenu_stop_recording_action;
    QAction *editMenu_play_recording_action;


    QAction *searchMenu_search_action;   //search菜单项
    QAction *searchMenu_search_files_action;
    QAction *searchMenu_search_project_action;
    QAction *searchMenu_lookup_reference_action;
    QAction *searchMenu_search_forward_action;
    QAction *searchMenu_search_backwardaction;

    QAction *searchMenu_replace_action;
    QAction *searchMenu_replace_files_action;

    QAction *searchMenu_bookmar_action;
    QAction *searchMenu_select_history_action;
    QAction *searchMenu_go_to_line_action;

    QAction *searchMenu_go_back_action;
    QAction *searchMenu_go_forward_action;
    QAction *searchMenu_jump_to_link_action;
    QAction *searchMenu_go_to_previous_link_action;
    QAction *searchMenu_go_to_next_link_action;
    QAction *searchMenu_parse_source_links_action;

    QAction *searchMenu_browser_project_symbols_aciton;
    QAction *searchMenu_browser_local_file_symbols_action;
    QAction *searchMenu_jump_to_definition_action;


    QAction *projectMenu_new_project_action;  //project菜单选项
    QAction *projectMenu_open_project_action;
    QAction *projectMenu_close_project_action;
    QAction *projectMenu_remove_project_action;

    QAction *projectMenu_add_and_remove_project_files_action;
    QAction *projectMenu_synchronize_files_action;

    QAction *projectMenu_project_report_action;
    QAction *projectMenu_rebuild_project_action;

    QAction *projectMenu_project_settings_action;


    QAction *optionMenu_preferences_action;

    QAction *optionMenu_document_options_action;
    QAction *optionMenu_style_properties_action;

    QAction *optionMenu_key_assignments_action;
    QAction *optionMenu_menu_assignments_action;
    QAction *optionMenu_custom_commands_action;

    QAction *optionMenu_load_configuration_action;
    QAction *optionMenu_save_configuration_action;



    QMenu *viewMenu_toolbars;   //view 菜单项
    QAction *viewMenu_toolbars_action_main_toolbar;
    QAction *viewMenu_toolbars_action_standard;
    QAction *viewMenu_toolbars_action_edit;
    QAction *viewMenu_toolbars_action_search;
    QAction *viewMenu_toolbars_action_navigation;
    QAction *viewMenu_toolbars_action_symbols;
    QAction *viewMenu_toolbars_action_arrangement;
    QAction *viewMenu_toolbars_action_view;
    QAction *viewMenu_toolbars_action_help;
    QAction *viewMenu_toolbars_action_source_control;
    QAction *viewMenu_toolbars_action_build;

    QAction *viewMenu_status_bar_action;
    QAction *viewMenu_horizontal_scroll_bar_action;
    QAction *viewMenu_line_number_action;

    QAction *viewMenu_project_window_action;
    QAction *viewMenu_clip_window_action;
    QAction *viewMenu_symbol_window_action;
    QAction *viewMenu_context_window_action;
    QAction *viewMenu_relation_window_action;
    QAction *viewMenu_show_clipboard_action;
    QAction *viewMenu_draft_view_action;

    QAction *windowMenu_new_window_action; //window菜单项
    QAction *windowMenu_close_window_action;

    QAction *windowMenu_Cascade_window_action;
    QAction *windowMenu_title_horizontal_action;
    QAction *windowMenu_title_vertical_action;
    QAction *windowMenu_title_one_widnow_action;
    QAction *windowMenu_title_two_window_action;


    QAction *windowMenu_link_window_action;
    QAction *windowMenu_link_all_windows_action;
    QAction *windowMenu_windows_list_action;


    QAction *helpMenu_help_action;
    QAction *helpMenu_help_mode_action;
    QAction *helpMenu_html_help_aciton;
    QAction *helpMenu_sdk_help_action;
    QAction *helpMenu_create_key_list_action;
    QAction *helpMenu_create_command_list;

    QAction *helpMenu_ordering_information_action;
    QAction *helpMenu_serical_number_action;
    QAction *helpMenu_source_dynameics_on_the_web_action;
    QAction *helpMenu_about_source_insight_custom_action;
    QAction *helpMenu_bug_feedback_action;


    QToolBar  *file_toolbar;
    QToolBar  *edit_toolbar;
    QToolBar  *search_toolbar;
    QToolBar *windows_layout_toolbar;
    QToolBar *help_toolbar;
    QToolBar *exploer_view_toolbar;

     QList<QAction*> edit_do_list,basic_edit_list,edit_clip_list,select_list, editMenu_special_case_list,editMenu_special_space_tab_list,editMenu_special_charsets_list ,editMenu_special_indent_list, recording_list;
     QList<QAction*> searchMenu_one_list,searchMenu_two_list,searchMenu_three_list,searchMenu_four_list,searchMenu_five_list,searchMenu_six_list;
     QList<QAction*> projectMenu_one_list,projectMenu_two_list,projectMenu_three_list,projectMenu_four_list;
     QList<QAction*> optionMenu_one_list,optionMenu_two_list,optionMenu_three_list,optionMenu_four_list;
     QList<QAction*> viewMenu_one_list,viewMenu_two_list,viewMenu_three_list,viewMenu_four_list;
     QList<QAction*> windowMenu_one_list,windowMenu_two_list,windowMenu_three_list;//,windowMenu_four_list;
     QList<QAction*> helpMenu_one_list,helpMenu_two_list;
     QStatusBar *statusbar;
     BugFeedback *bugfeedback;
     PreferencesDlg *preferenceDlg;
private:
      TreeViewWid *treeViewWid;

private slots:
     void bug_feedback_slot();
     void file_exit();
     void preferenceSetting();
     void file_open();


};

#endif // MAINWINDOW_H
