<div id="data-portal-app" ng-controller="datacontroller" ng-cloak>
  
  <div class="datasets-number">There are currently {{row_count}} datasets and can be sorted by Center or the assay type.</div>

  <div style="margin-top: 10px;">Users must use data with <a href="https://ocg.cancer.gov/sites/default/files/CTD2CaveatEmptor_final.pdf">discretion</a> and acknowledge the <a href="https://ocg.cancer.gov/programs/ctd2/ctd2-publication-guidelines">CTD<sup>2</sup> Network</a>.</div>

  <div id="centers" ng-cloak>
    <a href ng-click="clickChoice = 'centers'; setRow(); projectTitle = ctd2nodes.nodes[0].node.title.title; setSelectedCenter(ctd2nodes.nodes[0].node.id); setSelectedProject(ctd2nodes.nodes[0].node.row[0].project_title.title)" ng-class="{'highlight':revealData(clickChoice), '':!highlight}" class="centers-icon centers-inner highlight"><img src="/sites/default/files/Round_Landmark_Icon_Generic_Building.svg_.png" style="width: 75px;" alt="{{ctd2nodes.nodes.length}} Centers" title="{{ctd2nodes.nodes.length}} Centers" /><span>Centers</span></a>
    <a href ng-click="clickChoice = 'method'; setMethod(methods[0].node[0].id, method.node[0].row_number); methodTitle = methods[0]; setSelectedAssay(methods[0].assay); setSelectedAssayProject(methods[0].node[0].project_title)" ng-class="{'highlight':!revealData(clickChoice), '':!highlight}" class="methods-icon lowlight"><img src="/sites/default/files/Test_Tube_Free_Flat_Vector_Icon_Outline.jpg" style="width: 75px;" alt="{{methods.length}} Methods" title="{{methods.length}} Methods" /><span>Methods</span></a>
    <div class="data-stack"></div>
  </div>

  <div class="portal-navigation" ng-cloak>

    <div id="center-title" ng-show="revealData(clickChoice)">
      <div class="center-title-inner">
        <div ng-repeat="project in ctd2nodes.nodes" class="project" ng-cloak>
          <div class="title" ng-show="project.node.row[0].project_title != NULL"><a ng-click="$parent.projectTitle = project.node.title.title; setRow(project.node.row[0].row_number); setSelectedCenter(project.node.id); setSelectedProject(project.node.row[0].project_title.title)" ng-class="{highlight:project.node.id === idSelectedCenter}">{{ project.node.title.title}}</a></div>
          <div title="{{project.node.title.attributes.title}}" class="title" ng-if="project.node.row[0].project_title == NULL">{{project.node.title.title}}</div>
          <div class="dataset-count">{{project.node.row[0].project_title != NULL ? project.node.row.length : 0}} Datasets</div>
        </div>
      </div>
    </div>

    <div id="method-title" ng-show="!revealData(clickChoice)">
      <div class="method-title-inner">
        <div ng-repeat="method in methods" class="project">
          <div class="title"><a ng-click="$parent.methodTitle = method; setMethod(method.row[0].id, method.row[0].row_number); setSelectedAssay(method.assay); setSelectedAssayProject(method.node[0].project_title)" ng-class="{highlight:method.assay === idSelectedAssay}">{{method.assay}}</a></div>
          <div class="dataset-count">{{method.number}} Datasets</div>
        </div>
      </div>
    </div>

    <div id="project-title" ng-show="revealData(clickChoice)">
      <div class="project-title-inner">
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row" class="project-title-inner-row">
            <a ng-click="setRow(row.row_number); changeClass(); setSelectedProject(row.project_title.title)" ng-class="{highlight:row.project_title.title === idSelectedProject}">{{row.project_title.title}}</a>
          </div>
        </div>
      </div>
    </div>

    <div id="method-project-title" ng-show="!revealData(clickChoice)">
      <div class="project-title-inner">
        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="row in method.node| limitTo:1" class="project-title-inner-row">
            <a ng-click="setMethod(row.id, row.row_number); setSelectedAssayProject(row.project_title)" ng-class="{highlight:row.project_title === idSelectedAssayProject}">{{row.project_title}}</a>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div id="row-info" ng-show="revealData(clickChoice)">
    <div class="row-info-approaches">
      <div id="experimental-approaches">

        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <h2>{{row.dpp.title}}</h2>
            <div class="approaches-description">
              <div ng-bind-html="row.dpp.body | crop: 200"></div><a href="/{{row.project_title.url}}"> {{row.dpp.body.length > 200 ? 'Read More...' : ''}}</a>
            </div>

            <div id="data">
              <h3 class="data-header">Data</h3>
              <img class="using-data" src="/sites/default/files/styles/80x80/public/USING%20DATA.png" />
              <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
                <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1" class="data-row">
                  <div ng-repeat="data in row.data">
                    Access the <a href="{{data.data_link.url}}">{{data.data_link.title}}</a>
                  </div>
                </div>
              </div>
            </div>

            <h3 class="approaches-header">Experimental Approaches</h3>
            <div ng-repeat="approach in row.dpp" class="approaches-listing">
              <div class="approaches-listing-title">{{approach.dpp_title}}</div>
              <div ng-bind-html="approach.dpp_body | crop: 150"></div><a href="/{{row.project_title.url}}"> {{approach.dpp_body.length > 150 ? 'Read More...' : ''}}</a>
            </div>
          </div>
        </div>
      </div>
    </div>

    <div class="row-info-remaining">

      <div id="investigator">
        <h3 class="investigator-header">Principal Investigator</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <div ng-repeat="investigator in row.investigator">
              <div>{{investigator.investigator}}</div>
            </div>
          </div>
        </div>
      </div>

      <div id="contact">
        <h3 class="contact-header">Contact Name</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <div ng-repeat="contact in row.contact">
              <div ng-repeat="contact_link in contact.contact_link">
                <a href="{{contact_link.url}}">{{contact_link.title}}</a>
              </div>
            </div>
          </div>
        </div>
      </div>

      <!-- div id="submission-date">
        <h3 class="submission-date-header">Submission Date</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <div>{{row.submission_date * 1000| date : "y-MM-dd"}}</div>
          </div>
        </div>
      </div -->

      <div id="reference">
        <!-- h3 class="reference-header" ng-if="ctd2nodes.nodes[0].node[0].row[0].paper[0].paper_link.url == NULL">Reference</h3 -->
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <h3 class="reference-header" ng-if="row.paper[0].paper_link.url !== NULL">Reference</h3>
            <div ng-repeat="paper in row.paper">
              <a href="{{paper.paper_link.url}}">{{paper.paper_link.title}}</a>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div id="method-row-info" ng-show="!revealData(clickChoice)">
    <div class="row-info-approaches">
      <div id="experimental-approaches">

        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
            <h2>{{row.dpp_title}}</h2>
            <div class="approaches-description">
              <div ng-bind-html="row.dpp_body | crop: 200"></div><a href="/{{row.project_title_url}}"> {{row.dpp_body.length > 200 ? 'Read More...' : ''}}</a>
            </div>

            <div id="data">
              <h3 class="data-header">Data</h3>
              <img class="using-data" src="/sites/default/files/styles/80x80/public/USING%20DATA.png" />
              <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
                <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1" class="data-row">
                  <div ng-repeat="data in row.data">
                    Access the <a href="{{data.data_url}}">{{data.data_title}}</a>
                  </div>
                </div>
              </div>
            </div>

            <h3 class="approaches-header">Experimental Approaches</h3>
            <div ng-repeat="approach in row.dpp" class="approaches-listing">
              <div class="approaches-listing-title">{{approach.dpp_title}}</div>
              <div ng-bind-html="approach.dpp_body | crop: 150"></div><a href="/{{row.project_title_url}}"> {{approach.dpp_body.length > 150 ? 'Read More...' : ''}}</a>
            </div>
          </div>
        </div>
      </div>
    </div>

    <div class="row-info-remaining">

      <div id="investigator">
        <h3 class="investigator-header">Principal Investigator</h3>
        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
            <div ng-repeat="investigator in row.investigator">
              <div>{{investigator.investigator}}</div>
            </div>
          </div>
        </div>
      </div>

      <div id="contact">
        <h3 class="contact-header">Contact Name</h3>
        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
            <div ng-repeat="contact in row.contact">
              <div ng-repeat="contact_link in contact.contact_link">
                <a href="{{contact_link.url}}">{{contact_link.title}}</a>
              </div>
            </div>
          </div>
        </div>
      </div>

      <!-- div id="submission-date">
        <h3 class="submission-date-header">Submission Date</h3>
        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
            <div>{{row.submission_date * 1000| date : "y-MM-dd"}}</div>
          </div>
        </div>
      </div -->

      <div id="reference">
        <!-- h3 class="reference-header">Reference</h3 -->
        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
            <h3 class="reference-header" ng-if="row.paper[0].paper_title !== NULL">Reference</h3>
            <div ng-repeat="paper in row.paper">
              <a href="{{paper.paper_url}}">{{paper.paper_title}}</a>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

</div>