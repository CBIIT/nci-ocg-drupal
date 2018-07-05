<div id="data-portal-app" ng-controller="datacontroller" ng-cloak>

  <div class="portal-navigation">
    <div id="centers">
      <a href ng-click="clickChoice = 'centers'; setRow(); projectTitle = ctd2nodes.nodes[0].node.title.title; setSelectedCenter(ctd2nodes.nodes[0].node.id); setSelectedProject(ctd2nodes.nodes[0].node.row[0].project_title.title)" ng-class="{'highlight':revealData(clickChoice), '':!highlight}" class="centers-inner highlight">{{ctd2nodes.nodes.length}} Centers</a>
      <a href ng-click="clickChoice = 'method'; setMethod(methods[0].node[0].id, method.node[0].row_number); methodTitle = methods[0]; setSelectedAssay(methods[0].assay); setSelectedAssayProject(methods[0].node[0].project_title)" ng-class="{'highlight':!revealData(clickChoice), '':!highlight}" class="lowlight">{{methods.length}} Methods</a>
    </div>

    <div id="center-title" ng-show="revealData(clickChoice)">
      <div ng-class="center-title-inner">
        <div ng-repeat="project in ctd2nodes.nodes" class="project">
          <div class="title"><a ng-click="$parent.projectTitle = project.node.title.title; setRow(project.node.row[0].row_number); setSelectedCenter(project.node.id); setSelectedProject(project.node.row[0].project_title.title)" ng-class="{highlight:project.node.id === idSelectedCenter}">{{ project.node.title.title}}</a></div>
          <div class="dataset-count">{{project.node.row.length}} Datasets</div>
        </div>
      </div>
    </div>

    <div id="method-title" ng-show="!revealData(clickChoice)">
      <div ng-class="method-title-inner">
        <div ng-repeat="method in methods" class="project">
          <div class="title"><a ng-click="$parent.methodTitle = method; setSelectedAssay(method.assay); setSelectedAssayProject(method.node[0].project_title)" ng-class="{highlight:method.assay === idSelectedAssay}">{{method.assay}}</a></div>
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
              <div ng-bind-html="row.dpp.body | crop: 200"></div><a href="{{row.project_title.url}}"> {{row.dpp.body.length > 200 ? 'Read More...' : ''}}</a>
            </div>

            <div id="data">
              <h3 class="data-header">Data</h3>
              <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
                <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
                  <div ng-repeat="data in row.data">
                    Access the <a href="/{{data.data_link.url}}">{{data.data_link.title}}</a>
                  </div>
                </div>
              </div>
            </div>

            <h3 class="approaches-header">Experimental Approaches</h3>
            <div ng-repeat="approach in row.dpp" class="approaches-listing">
              <div class="approaches-listing-title">{{approach.dpp_title}}</div>
              <div ng-bind-html="approach.dpp_body | crop: 150"></div><a href="{{row.project_title.url}}"> {{approach.dpp_body.length > 150 ? 'Read More...' : ''}}</a>
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
                <a href="/{{contact_link.url}}">{{contact_link.title}}</a>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div id="submission-date">
        <h3 class="submission-date-header">Submission Date</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <div>{{row.submission_date * 1000| date : "y-MM-dd"}}</div>
          </div>
        </div>
      </div>

      <div id="reference">
        <h3 class="reference-header">Reference</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <div ng-repeat="paper in row.paper">
              <a href="/{{paper.paper_link.url}}">{{paper.paper_link.title}}</a>
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
              <div ng-bind-html="row.dpp_body | crop: 200"></div><a href="{{row.project_title_url}}"> {{row.dpp_body.length > 200 ? 'Read More...' : ''}}</a>
            </div>

            <div id="data">
              <h3 class="data-header">Data</h3>
              <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
                <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
                  <div ng-repeat="data in row.data">
                    Access the <a href="/{{data.data_url}}">{{data.data_title}}</a>
                  </div>
                </div>
              </div>
            </div>

            <h3 class="approaches-header">Experimental Approaches</h3>
            <div ng-repeat="approach in row.dpp" class="approaches-listing">
              <div class="approaches-listing-title">{{approach.dpp_title}}</div>
              <div ng-bind-html="approach.dpp_body | crop: 150"></div><a href="{{row.project_title_url}}"> {{approach.dpp_body.length > 150 ? 'Read More...' : ''}}</a>
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
                <a href="/{{contact_link.url}}">{{contact_link.title}}</a>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div id="submission-date">
        <h3 class="submission-date-header">Submission Date</h3>
        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
            <div>{{row.submission_date * 1000| date : "y-MM-dd"}}</div>
          </div>
        </div>
      </div>

      <div id="reference">
        <h3 class="reference-header">Reference</h3>
        <div ng-repeat="method in methods| filter:methodTitle | limitTo:1">
          <div ng-repeat="(key, row) in filterMethodRow(method.node)" ng-if="$index < 1">
            <div ng-repeat="paper in row.paper">
              <a href="/{{paper.paper_url}}">{{paper.paper_title}}</a>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

</div>