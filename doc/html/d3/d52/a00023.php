<!-- HTML header for doxygen 1.8.11-->
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/xhtml;charset=UTF-8"/>
		<meta http-equiv="X-UA-Compatible" content="IE=9"/>
		<meta name="generator" content="Doxygen 1.8.13"/>
		<title>Planning Generator: MainWindow_TabPlanning.h File Reference</title>
		<link href="../../tabs.css" rel="stylesheet" type="text/css"/>
		<script type="text/javascript" src="../../jquery.js"></script>
		<script type="text/javascript" src="../../dynsections.js"></script>
		<link href="../../navtree.css" rel="stylesheet" type="text/css"/>
<script type="text/javascript" src="../../resize.js"></script>
<script type="text/javascript" src="../../navtreedata.js"></script>
<script type="text/javascript" src="../../navtree.js"></script>
<script type="text/javascript">
  $(document).ready(initResizable);
</script>
		<link href="../../search/search.css" rel="stylesheet" type="text/css"/>
<script type="text/javascript" src="../../search/searchdata.js"></script>
<script type="text/javascript" src="../../search/search.js"></script>
		<link href="../../doxygen.css" rel="stylesheet" type="text/css" />
		<link href="../../doxystyle.css" rel="stylesheet" type="text/css"/>
	</head>
	<body>
		<div id="top"><!-- do not remove this div, it is closed by doxygen! -->
			<div id="titlearea">
				<table cellspacing="0" cellpadding="0">
					<tbody>
						<tr style="height: 56px;">
							<td id="projectalign" style="padding-left: 0.5em;">
								<div id="projectname">Planning Generator
									&#160;<span id="projectnumber">1.0</span>
								</div>
								<div id="projectbrief">A software to generate some plannings according to specifications.</div>
							</td>
						</tr>
					</tbody>
				</table>
			</div>
			<?php
				$text = "Generated on Wed Nov 27 2019 12:22:26 for Planning Generator by";
				$text = substr($text, 0, sizeof($text) - 4);
				$tmp = substr($text, 17);
				$tmp = substr($tmp, 0, strpos($tmp, " for"));
				$lastModif = date("l jS \of F Y \a\\t H:i:s", strtotime($tmp));
			?>
		<!-- end header part -->
<!-- Generated by Doxygen 1.8.13 -->
<script type="text/javascript">
var searchBox = new SearchBox("searchBox", "../../search",false,'Search');
</script>
<script type="text/javascript" src="../../menudata.js"></script>
<script type="text/javascript" src="../../menu.js"></script>
<script type="text/javascript">
$(function() {
  initMenu('../../',true,false,'search.php','Search');
  $(document).ready(function() { init_search(); });
});
</script>
<div id="main-nav"></div>
</div><!-- top -->
<div id="side-nav" class="ui-resizable side-nav-resizable">
  <div id="nav-tree">
    <div id="nav-tree-contents">
      <div id="nav-sync" class="sync"></div>
    </div>
  </div>
  <div id="splitbar" style="-moz-user-select:none;" 
       class="ui-resizable-handle">
  </div>
</div>
<script type="text/javascript">
$(document).ready(function(){initNavTree('d3/d52/a00023.php','../../');});
</script>
<div id="doc-content">
<!-- window showing the filter options -->
<div id="MSearchSelectWindow"
     onmouseover="return searchBox.OnSearchSelectShow()"
     onmouseout="return searchBox.OnSearchSelectHide()"
     onkeydown="return searchBox.OnSearchSelectKey(event)">
</div>

<!-- iframe showing the search results (closed by default) -->
<div id="MSearchResultsWindow">
<iframe src="javascript:void(0)" frameborder="0" 
        name="MSearchResults" id="MSearchResults">
</iframe>
</div>

<div class="header">
  <div class="summary">
<a href="#define-members">Macros</a> &#124;
<a href="#func-members">Functions</a> &#124;
<a href="#var-members">Variables</a>  </div>
  <div class="headertitle">
<div class="title">MainWindow_TabPlanning.h File Reference</div>  </div>
</div><!--header-->
<div class="contents">
<div class="textblock"><div class="dynheader">
This graph shows which files directly or indirectly include this file:</div>
<div class="dyncontent">
<div class="center"><img src="../../d3/dfe/a00025.png" border="0" usemap="#MainWindow__TabPlanning_8hdep" alt=""/></div>
<map name="MainWindow__TabPlanning_8hdep" id="MainWindow__TabPlanning_8hdep">
<area shape="rect" id="node2" href="../../d4/d51/a00017.php" title="MainWindow.h" alt="" coords="45,80,153,107"/>
<area shape="rect" id="node3" href="../../d4/dee/a00008.php" title="ConnectWindow.h" alt="" coords="34,155,163,181"/>
</map>
</div>
</div><table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a name="define-members"></a>
Macros</h2></td></tr>
<tr class="memitem:ac1473eae2abbeb88e2a14d0de2b1a434"><td class="memItemLeft" align="right" valign="top">#define&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d4/d51/a00017.php#ac1473eae2abbeb88e2a14d0de2b1a434">HEADER_MAINWINDOW_TAB_PLANNING</a></td></tr>
<tr class="separator:ac1473eae2abbeb88e2a14d0de2b1a434"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table><table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a name="func-members"></a>
Functions</h2></td></tr>
<tr class="memitem:a349ff21c7788a0de0e7f550525c2b297"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#a349ff21c7788a0de0e7f550525c2b297">p_setAll</a> (const <a class="el" href="../../d0/d8d/a00612.php">Globals</a> &amp;gl, const std::vector&lt; <a class="el" href="../../db/ddc/a00636.php">TeamMember</a> &gt; &amp;tm, const <a class="el" href="../../d3/dd6/a00624.php">Planning</a> &amp;pl)</td></tr>
<tr class="separator:a349ff21c7788a0de0e7f550525c2b297"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a5544cfa9bbbfd8c1ce7f2ae0d8d2936c"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#a5544cfa9bbbfd8c1ce7f2ae0d8d2936c">initPlanningTab</a> (QTabWidget *tabWidget)</td></tr>
<tr class="separator:a5544cfa9bbbfd8c1ce7f2ae0d8d2936c"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:af16aec1b6ed5afba4221826e891710d9"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#af16aec1b6ed5afba4221826e891710d9">resetPlanningTab</a> (QTabWidget *tabWidget)</td></tr>
<tr class="separator:af16aec1b6ed5afba4221826e891710d9"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a3036d4f825a7875f7be98b4a23d5e8c7"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#a3036d4f825a7875f7be98b4a23d5e8c7">deletePlanningTab</a> (QTabWidget *tabWidget)</td></tr>
<tr class="separator:a3036d4f825a7875f7be98b4a23d5e8c7"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table><table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a name="var-members"></a>
Variables</h2></td></tr>
<tr class="memitem:a475e73047eb49e0a343b0ce698940ff6"><td class="memItemLeft" align="right" valign="top"><a class="el" href="../../d0/d8d/a00612.php">Globals</a>&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#a475e73047eb49e0a343b0ce698940ff6">_p_globals</a></td></tr>
<tr class="separator:a475e73047eb49e0a343b0ce698940ff6"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:aae400d773085b3f43d74f1e2a7ca9ad4"><td class="memItemLeft" align="right" valign="top">std::vector&lt; <a class="el" href="../../db/ddc/a00636.php">TeamMember</a> &gt;&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#aae400d773085b3f43d74f1e2a7ca9ad4">_p_teamMembers</a></td></tr>
<tr class="separator:aae400d773085b3f43d74f1e2a7ca9ad4"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a75562f150b0ccf10fc44b3e5c114b623"><td class="memItemLeft" align="right" valign="top">QWidget *&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#a75562f150b0ccf10fc44b3e5c114b623">_planningTab</a></td></tr>
<tr class="separator:a75562f150b0ccf10fc44b3e5c114b623"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a32ce8d745a199d80acf30735d87182bc"><td class="memItemLeft" align="right" valign="top">QVBoxLayout *&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#a32ce8d745a199d80acf30735d87182bc">_planningLay</a></td></tr>
<tr class="separator:a32ce8d745a199d80acf30735d87182bc"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a2f9640096754da371c94ea3bfa15612a"><td class="memItemLeft" align="right" valign="top"><a class="el" href="../../d3/dd6/a00624.php">Planning</a>&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="../../d3/d52/a00023.php#a2f9640096754da371c94ea3bfa15612a">_planning</a></td></tr>
<tr class="separator:a2f9640096754da371c94ea3bfa15612a"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table>
<h2 class="groupheader">Macro Definition Documentation</h2>
<a id="ac1473eae2abbeb88e2a14d0de2b1a434"></a>
<h2 class="memtitle"><span class="permalink"><a href="#ac1473eae2abbeb88e2a14d0de2b1a434">&#9670;&nbsp;</a></span>HEADER_MAINWINDOW_TAB_PLANNING</h2>

<div class="memitem">
<div class="memproto">
      <table class="memname">
        <tr>
          <td class="memname">#define HEADER_MAINWINDOW_TAB_PLANNING</td>
        </tr>
      </table>
</div><div class="memdoc">

</div>
</div>
<h2 class="groupheader">Function Documentation</h2>
<a id="a3036d4f825a7875f7be98b4a23d5e8c7"></a>
<h2 class="memtitle"><span class="permalink"><a href="#a3036d4f825a7875f7be98b4a23d5e8c7">&#9670;&nbsp;</a></span>deletePlanningTab()</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">void deletePlanningTab </td>
          <td>(</td>
          <td class="paramtype">QTabWidget *&#160;</td>
          <td class="paramname"><em>tabWidget</em></td><td>)</td>
          <td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">private</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
<a id="a5544cfa9bbbfd8c1ce7f2ae0d8d2936c"></a>
<h2 class="memtitle"><span class="permalink"><a href="#a5544cfa9bbbfd8c1ce7f2ae0d8d2936c">&#9670;&nbsp;</a></span>initPlanningTab()</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">void initPlanningTab </td>
          <td>(</td>
          <td class="paramtype">QTabWidget *&#160;</td>
          <td class="paramname"><em>tabWidget</em></td><td>)</td>
          <td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">private</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
<a id="a349ff21c7788a0de0e7f550525c2b297"></a>
<h2 class="memtitle"><span class="permalink"><a href="#a349ff21c7788a0de0e7f550525c2b297">&#9670;&nbsp;</a></span>p_setAll()</h2>

<div class="memitem">
<div class="memproto">
      <table class="memname">
        <tr>
          <td class="memname">void p_setAll </td>
          <td>(</td>
          <td class="paramtype">const <a class="el" href="../../d0/d8d/a00612.php">Globals</a> &amp;&#160;</td>
          <td class="paramname"><em>gl</em>, </td>
        </tr>
        <tr>
          <td class="paramkey"></td>
          <td></td>
          <td class="paramtype">const std::vector&lt; <a class="el" href="../../db/ddc/a00636.php">TeamMember</a> &gt; &amp;&#160;</td>
          <td class="paramname"><em>tm</em>, </td>
        </tr>
        <tr>
          <td class="paramkey"></td>
          <td></td>
          <td class="paramtype">const <a class="el" href="../../d3/dd6/a00624.php">Planning</a> &amp;&#160;</td>
          <td class="paramname"><em>pl</em>&#160;</td>
        </tr>
        <tr>
          <td></td>
          <td>)</td>
          <td></td><td></td>
        </tr>
      </table>
</div><div class="memdoc">

</div>
</div>
<a id="af16aec1b6ed5afba4221826e891710d9"></a>
<h2 class="memtitle"><span class="permalink"><a href="#af16aec1b6ed5afba4221826e891710d9">&#9670;&nbsp;</a></span>resetPlanningTab()</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">void resetPlanningTab </td>
          <td>(</td>
          <td class="paramtype">QTabWidget *&#160;</td>
          <td class="paramname"><em>tabWidget</em></td><td>)</td>
          <td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">private</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
<h2 class="groupheader">Variable Documentation</h2>
<a id="a475e73047eb49e0a343b0ce698940ff6"></a>
<h2 class="memtitle"><span class="permalink"><a href="#a475e73047eb49e0a343b0ce698940ff6">&#9670;&nbsp;</a></span>_p_globals</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname"><a class="el" href="../../d0/d8d/a00612.php">Globals</a> _p_globals</td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">protected</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
<a id="aae400d773085b3f43d74f1e2a7ca9ad4"></a>
<h2 class="memtitle"><span class="permalink"><a href="#aae400d773085b3f43d74f1e2a7ca9ad4">&#9670;&nbsp;</a></span>_p_teamMembers</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">std::vector&lt;<a class="el" href="../../db/ddc/a00636.php">TeamMember</a>&gt; _p_teamMembers</td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">protected</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
<a id="a2f9640096754da371c94ea3bfa15612a"></a>
<h2 class="memtitle"><span class="permalink"><a href="#a2f9640096754da371c94ea3bfa15612a">&#9670;&nbsp;</a></span>_planning</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname"><a class="el" href="../../d3/dd6/a00624.php">Planning</a> _planning</td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">private</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
<a id="a32ce8d745a199d80acf30735d87182bc"></a>
<h2 class="memtitle"><span class="permalink"><a href="#a32ce8d745a199d80acf30735d87182bc">&#9670;&nbsp;</a></span>_planningLay</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">QVBoxLayout* _planningLay</td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">private</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
<a id="a75562f150b0ccf10fc44b3e5c114b623"></a>
<h2 class="memtitle"><span class="permalink"><a href="#a75562f150b0ccf10fc44b3e5c114b623">&#9670;&nbsp;</a></span>_planningTab</h2>

<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">QWidget* _planningTab</td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">private</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">

</div>
</div>
</div><!-- contents -->
</div><!-- doc-content -->
<!-- HTML footer for doxygen 1.8.11-->
<!-- start footer part -->
<div id="nav-path" class="navpath"><!-- id is needed for treeview function! -->
	<ul>
		<li class="navelem"><a class="el" href="../../dir_ed26a3555d00e4455851f1edbe2abea5.php">UQAC</a></li><li class="navelem"><a class="el" href="../../dir_72411d72a30b0a1d05f4f299c6dfb7e5.php">Cours2019-2020</a></li><li class="navelem"><a class="el" href="../../dir_3980970c724e97a7cae3ad342bc5e88e.php">Cours</a></li><li class="navelem"><a class="el" href="../../dir_de660acd428597c95c4dbb5b7e7040d2.php">T1_Genie_logiciel</a></li><li class="navelem"><a class="el" href="../../dir_2ed2da8857c2ea9b402c35adb582720e.php">Projet</a></li><li class="navelem"><a class="el" href="../../dir_a775c7fce4d0a7a4e13e85e05d64f23a.php">project_GL_uqac_automne2019</a></li><li class="navelem"><a class="el" href="../../dir_11f7a8fe58957f41539c5c2e1ae91c25.php">inc</a></li><li class="navelem"><a class="el" href="../../d3/d52/a00023.php">MainWindow_TabPlanning.h</a></li>
		<li class="footer">
			<?php
				echo $text;
			?>
		</li>
	</ul>
</div>
</body>
</html>
